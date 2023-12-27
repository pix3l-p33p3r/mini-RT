/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:18:19 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/27 02:46:17 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	get_t2(t_ray *back_ray, t_vector *vhat, float *t, t_vector *poi)
{
	float		delta;
	float		a;
	float		b;
	float		c;
	t_vector	p;

	p = back_ray->point1;
	a = square(vhat->x) + square(vhat->y);
	b = 2.0 * (p.x * vhat->x + p.y * vhat->y);
	c = square(p.x) + square(p.y) - 1.0;
	delta = sqrtf(square(b) - (4.0 * a * c));
	if (delta > 0.0)
	{
		t[0] = (-b + delta) / (2.0f * a);
		t[1] = (-b - delta) / (2.0f * a);
		poi[0] = add_vec(back_ray->point1, scale_vec(*vhat, t[0]));
		poi[1] = add_vec(back_ray->point1, scale_vec(*vhat, t[1]));
		return (1);
	}
	return (0);
}

static float	get_distance(t_ray *back_ray, t_vector *vhat,
	float *t, t_vector *poi)
{
	float	t2;

	t2 = get_t2(back_ray, vhat, t, poi);
	if (!t2)
		return (MAXFLOAT);
	if (!(t[0] > 0.0 && fabs(poi[0].z) < 1.0))
		t[0] = 100e6;
	if (!(t[1] > 0.0 && fabs(poi[1].z) < 1.0))
		t[1] = 100e6;
	return (t2);
}

void	get_distance2(t_ray *back_ray, t_vector *vhat, float *t, t_vector *poi)
{
	float	t2;

	t2 = get_distance(back_ray, vhat, t, poi);
	if (t2 == MAXFLOAT)
	{
		t[0] = 100e6;
		t[1] = 100e6;
	}
	if (fabs(vhat->z) < EPSILON)
	{
		t[2] = 100e6;
		t[3] = 100e6;
		return ;
	}
	t[2] = (back_ray->point1.z - 1) / -vhat->z;
	t[3] = (back_ray->point1.z + 1) / -vhat->z;
	poi[2] = add_vec(back_ray->point1, scale_vec(*vhat, t[2]));
	poi[3] = add_vec(back_ray->point1, scale_vec(*vhat, t[3]));
	if (!(t[2] > 0.0 && sqrtf(square(poi[2].x) + square(poi[2].y)) < 1.0))
		t[2] = 100e6;
	if (!(t[3] > 0.0 && sqrtf(square(poi[3].x) + square(poi[3].y)) < 1.0))
		t[3] = 100e6;
}

float	get_min(float *t, int *min_index)
{
	float	min;
	int		i;

	i = 0;
	if (t[0] == 100e6 && t[1] == 100e6
		&& t[2] == 100e6 && t[3] == 100e6)
		return (-1);
	min = 10e6;
	while (i < 4)
	{
		if (t[i] < min)
		{
			min = t[i];
			*min_index = i;
		}
		i++;
	}
	return (min);
}

int	test_cylinder(t_ray *ray, t_info *info)
{
	t_ray		back_ray;
	t_vector	vhat;
	float		t[4];
	t_vector	poi[4];
	int			min_index;

	back_ray = apply_transform(ray, info->e->gtfm, BACKWARD);
	vhat = back_ray.direction;
	get_distance2(&back_ray, &vhat, t, poi);
	min_index = 0;
	if (get_min(t, &min_index) == -1)
		return (0);
	return (calculate_props(min_index, &poi[min_index], info, &vhat));
}
