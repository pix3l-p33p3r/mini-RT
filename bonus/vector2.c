/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:47:50 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 20:45:45 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float	length2(t_vector a)
{
	return (square(a.x) + square(a.y) + square(a.z));
}

float	length(t_vector a)
{
	return (sqrtf(length2(a)));
}
// returns a new normalized vector and keep the original

t_vector	normalized(t_vector a)
{
	t_vector	new;
	float		l;

	new = new_vec(a.x, a.y, a.z);
	l = length(a);
	if (l)
		new = scale_vec(new, 1.0f / l);
	return (new);
}

// project a at b and get the cos of the angle between them

float	dot_product(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
// get vector that is perpendecular to both a and b

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.y * b.z - a.z * b.y;
	new.y = a.z * b.x - a.x * b.z;
	new.z = a.x * b.y - a.y * b.x;
	return (new);
}
