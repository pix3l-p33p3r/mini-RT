/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:49:25 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 19:49:35 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_vector	reflect(t_vector d, t_vector normal)
{
	return (normalized(sub_vec(d,
				scale_vec(normal, 2 * dot_product(d, normal)))));
}

t_vector	get_rotation_vector(t_vector normal)
{
	float	x;
	float	y;
	float	z;

	x = atan2(normal.y, -normal.z);
	y = atan2(-normal.x, sqrtf(square(normal.y) + square(normal.z)));
	z = atan2(normal.x, normal.y);
	return (new_vec(x, y, z));
}
