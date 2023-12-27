/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:18:20 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/27 03:50:53 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	cast_ray(t_object *objects, t_ray *ray)
{
	int		validint;
	int		i;
	t_info	test;

	i = -1;
	validint = 0;
	while (objects[++i].gtfm)
	{
		test.e = &objects[i];
		validint = objects[i].hit(ray, &test);
		if (validint)
			break ;
	}
	return (validint);
}

static void	func1(t_norm6 *norm, t_info *info, t_vars *vars, t_ray *camera_ray)
{
	norm->intensity = 0;
	norm->lighdir = normalized(sub_vec(
				vars->lights[norm->i].position, info->hitpoint));
	norm->start = add_vec(info->hitpoint, scale_vec(norm->lighdir, 0.001f));
	norm->light_ray = new_ray(norm->start, add_vec(norm->start, norm->lighdir));
	norm->validint = cast_ray(vars->objects, &norm->light_ray);
	if (!norm->validint)
	{
		norm->r = reflect(normalized(
					norm->light_ray.direction), info->normal);
		norm->v = normalized(camera_ray->direction);
		norm->prod = dot_product(norm->r, norm->v);
		if (norm->prod > 0.0)
			norm->intensity = info->e->reflectivity
				* powf(norm->prod, info->e->shininess);
	}
}

t_vector	specular_highlight(t_info *info, t_vars *vars, t_ray *camera_ray)
{
	t_norm6	norm;

	norm.i = -1;
	norm.red = 0;
	norm.green = 0;
	norm.blue = 0;
	while (++norm.i < vars->pos1)
	{
		func1(&norm, info, vars, camera_ray);
		norm.red += vars->lights[norm.i].color.x
			* norm.intensity * vars->lights[norm.i].intensity;
		norm.green += vars->lights[norm.i].color.y * norm.intensity
			* vars->lights[norm.i].intensity;
		norm.blue += vars->lights[norm.i].color.z
			* norm.intensity * vars->lights[norm.i].intensity;
	}
	norm.spc_color = new_vec(norm.red, norm.green, norm.blue);
	return (norm.spc_color);
}

t_vector	compute_color(t_vars *vars, t_info *info, t_ray *camera_ray)
{
	t_vector	color;
	t_vector	diff_color;
	t_vector	spc_color;

	diff_color = diffuse(info, vars);
	spc_color = new_vec(0, 0, 0);
	if (info->e->has_material == 1 && info->e->shininess > 0)
		spc_color = specular_highlight(info, vars, camera_ray);
	color = add_vec(diff_color, spc_color);
	color = add_vec(color, vars->ambient->color);
	return (color);
}
