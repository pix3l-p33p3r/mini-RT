/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:34:40 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 19:55:16 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_ray	new_ray(t_vector point1, t_vector point2)
{
	t_ray	ray;

	ray.point1 = point1;
	ray.point2 = point2;
	ray.direction = sub_vec(point2, point1);
	return (ray);
}

t_ray	generate_ray(float x, float y, t_camera *camera)
{
	t_vector	part1;
	t_vector	part2;

	part1 = add_vec(camera->screen_center, scale_vec(camera->screen_u, x));
	part2 = add_vec(part1, scale_vec(camera->screen_v, y));
	return (new_ray(camera->origin, part2));
}
