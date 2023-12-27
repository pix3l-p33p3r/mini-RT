/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:51:06 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 21:22:13 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	test_plane(t_ray *ray, t_info *info)
{
	float		d;
	float		denom;
	float		t;
	t_vector	axis;

	axis = normalized(info->e->d_normal);
	d = -dot_product(axis, info->e->translation);
	denom = dot_product(axis, ray->direction);
	if (fabs(denom) < EPSILON)
		return (0);
	t = (-d - dot_product(ray->point1, axis)) / denom;
	if (t < EPSILON)
		return (0);
	info->normal = axis;
	if (dot_product(info->normal, ray->direction) > 0)
		info->normal = scale_vec(info->normal, -1);
	info->hitpoint = add_vec(ray->point1, scale_vec(ray->direction, t));
	return (1);
}
