/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:15:13 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/27 02:45:59 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

float	get_distance(t_ray back_ray, t_vector ray_dir)
{
	float	t1;
	float	t2;
	float	b;
	float	c;
	float	delta;

	b = 2 * dot_product(ray_dir, back_ray.point1);
	c = dot_product(back_ray.point1, back_ray.point1) - 1.0f;
	delta = square(b) - (4 * c);
	if (delta <= 0)
		return (MAXFLOAT);
	t1 = (-b - sqrtf(delta)) / 2.0f;
	t2 = (-b + sqrtf(delta)) / 2.0f;
	if (t1 < 0 || t2 < 0)
		return (MAXFLOAT);
	if (t2 < t1)
		return (t2);
	return (t1);
}

int	test_sphere(t_ray *ray, t_info *info)
{
	t_norm	norm;

	norm.back_ray = apply_transform(ray, info->e->gtfm, BACKWARD);
	norm.ray_dir = normalized(norm.back_ray.direction);
	norm.b = 2 * dot_product(norm.ray_dir, norm.back_ray.point1);
	norm.c = dot_product(norm.back_ray.point1, norm.back_ray.point1) - 1.0f;
	norm.delta = square(norm.b) - (4 * norm.c);
	if (norm.delta < 0)
		return (0);
	norm.t1 = (-norm.b - sqrtf(norm.delta)) / 2.0f;
	norm.t2 = (-norm.b + sqrtf(norm.delta)) / 2.0f;
	if (norm.t1 < 0 || norm.t2 < 0)
		return (0);
	if (norm.t2 < norm.t1)
		norm.localpoi = add_vec(norm.back_ray.point1,
				scale_vec(norm.ray_dir, norm.t2));
	else
		norm.localpoi = add_vec(norm.back_ray.point1,
				scale_vec(norm.ray_dir, norm.t1));
	info->hitpoint = apply_transform_vector(&norm.localpoi,
			info->e->gtfm, FORWARD);
	info->normal = normalized(sub_vec(info->hitpoint, info->e->translation));
	return (1);
}
