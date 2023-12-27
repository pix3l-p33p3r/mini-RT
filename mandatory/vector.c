/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:38:38 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 19:49:10 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

float	square(float a)
{
	return (a * a);
}

t_vector	new_vec(float x, float y, float z)
{
	return ((t_vector){x, y, z});
}

t_vector	sub_vec(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	add_vec(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	scale_vec(t_vector a, float t)
{
	return ((t_vector){a.x * t, a.y * t, a.z * t});
}
