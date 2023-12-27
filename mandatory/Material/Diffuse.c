/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:07:00 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/27 03:51:00 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	cast_ray(t_ray *ray, t_object *objects,
	t_info *info, float lighdist)
{
	t_norm3	norm;

	norm.i = -1;
	norm.validint = 0;
	while (objects[++norm.i].gtfm)
	{
		if (info->e == &objects[norm.i])
		{
			norm.i++ ;
			continue ;
		}
		norm.test.e = &objects[norm.i];
		norm.validint = objects[norm.i].hit(ray, &norm.test);
		if (norm.validint)
		{
			norm.dist = length(sub_vec(norm.test.hitpoint, ray->point1));
			if (norm.dist > lighdist)
				norm.validint = 0;
			else
				break ;
		}
	}
	return (norm.validint);
}

int	compute_illumination(t_light *light, t_object *objects,
	t_info *info, float *intensity)
{
	t_norm4	norm;

	norm.i = 0;
	norm.lighdir = normalized(sub_vec(light->position, info->hitpoint));
	norm.lighdist = length(sub_vec(light->position, info->hitpoint));
	norm.light_ray = new_ray(info->hitpoint,
			add_vec(info->hitpoint, norm.lighdir));
	norm.validint = cast_ray(&norm.light_ray, objects, info, norm.lighdist);
	if (!norm.validint)
	{
		norm.illumination = 1;
		*intensity = light->intensity * fmax(
				dot_product(info->normal, norm.lighdir), 0);
	}
	else
	{
		norm.illumination = 0;
		*intensity = 0;
	}
	return (norm.illumination);
}

t_vector	diffuse(t_info *info, t_vars *vars)
{
	t_norm5	norm;

	norm.i = -1;
	norm.red = 0;
	norm.green = 0;
	norm.blue = 0;
	norm.intensity = 0;
	while (++norm.i < vars->pos1)
	{
		norm.valid_ilum = compute_illumination
			(&vars->lights[norm.i], vars->objects, info, &norm.intensity);
		if (norm.valid_ilum)
		{
			norm.red += vars->lights[norm.i].color.x * norm.intensity;
			norm.green += vars->lights[norm.i].color.y * norm.intensity;
			norm.blue += vars->lights[norm.i].color.z * norm.intensity;
		}
	}
	norm.diff_color = new_vec(norm.red * info->e->base_color.x,
			norm.green * info->e->base_color.y,
			norm.blue * info->e->base_color.z);
	return (norm.diff_color);
}
