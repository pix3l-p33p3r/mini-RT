/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:18:19 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 21:18:23 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	calculate_props_case1(int min_index,
	t_vector *poi, t_info *info, t_vector *vhat)
{
	t_vector	orgnormal;

	(void) vhat;
	if (min_index < 2)
	{
		info->hitpoint = apply_transform_vector(poi, info->e->gtfm, FORWARD);
		orgnormal = new_vec(poi->x, poi->y, 0);
		orgnormal = apply_transform_vector(&orgnormal, info->e->gtfm, FORWARD);
		info->normal = normalized(sub_vec(orgnormal, info->e->translation));
		return (1);
	}
	return (0);
}

static int	calculate_props_case2(int min_index, t_vector *poi,
	t_info *info, t_vector *vhat)
{
	t_vector	orgnormal;

	(void) min_index;
	if (fabs(vhat->z) < EPSILON)
		return (0);
	if (sqrtf(square(poi->x) + square(poi->y)) < 1.0)
	{
		info->hitpoint = apply_transform_vector(poi, info->e->gtfm, FORWARD);
		orgnormal = new_vec(0, 0, poi->z);
		orgnormal = apply_transform_vector(&orgnormal, info->e->gtfm, FORWARD);
		info->normal = normalized(sub_vec(orgnormal, info->e->translation));
		return (1);
	}
	return (0);
}

int	calculate_props(int min_index, t_vector *poi, t_info *info, t_vector *vhat)
{
	if (min_index < 2)
		return (calculate_props_case1(min_index, poi, info, vhat));
	else
		return (calculate_props_case2(min_index, poi, info, vhat));
}
