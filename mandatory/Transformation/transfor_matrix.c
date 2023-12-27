/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfor_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:32:54 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 20:14:02 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_vector	apply_transform_vector(t_vector *input,
	t_matrix **gtfm, int dirflag)
{
	t_vector	output;
	t_matrix	*tempdata;
	t_matrix	*result;
	float		*values;

	tempdata = create_matrix(4, 1);
	values = (float []){input->x, input->y, input->z, 1.0f};
	fill_mt(tempdata, values);
	if (dirflag)
		result = mt_multiplication(gtfm[0], tempdata);
	else
		result = mt_multiplication(gtfm[1], tempdata);
	if (!result)
		return ((t_vector){0, 0, 0});
	output = new_vec(result->matrix[0][0],
			result->matrix[1][0], result->matrix[2][0]);
	delete_matrix(result);
	delete_matrix(tempdata);
	return (output);
}

t_ray	apply_transform(t_ray *ray, t_matrix **gtfm, int dirflag)
{
	t_ray	new_ray;

	new_ray.point1 = apply_transform_vector(&ray->point1, gtfm, dirflag);
	new_ray.point2 = apply_transform_vector(&ray->point2, gtfm, dirflag);
	new_ray.direction = sub_vec(new_ray.point2, new_ray.point1);
	return (new_ray);
}

t_matrix	**set_transform(t_vector t, t_vector r, t_vector s)
{
	t_matrix	**transform;
	t_matrix	*forward;
	t_matrix	*backward;

	transform = malloc(sizeof(t_matrix *) * 2);
	forward = safe_matrix_multy(translation_matrix(&t), rotation_matrix_x(r.x));
	forward = safe_matrix_multy(forward, rotation_matrix_y(r.y));
	forward = safe_matrix_multy(forward, rotation_matrix_z(r.z));
	forward = safe_matrix_multy(forward, scaling_matrix(&s));
	backward = inverse(forward);
	transform[0] = forward;
	transform[1] = backward;
	return (transform);
}
