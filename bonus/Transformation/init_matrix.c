/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:27:55 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 20:03:11 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_matrix	*translation_matrix(t_vector *v)
{
	t_matrix	*translation;

	translation = create_matrix(4, 4);
	set_to_indentity(translation);
	translation->matrix[0][3] = v->x;
	translation->matrix[1][3] = v->y;
	translation->matrix[2][3] = v->z;
	return (translation);
}

t_matrix	*scaling_matrix(t_vector *v)
{
	t_matrix	*scaling;

	scaling = create_matrix(4, 4);
	set_to_indentity(scaling);
	scaling->matrix[0][0] = v->x;
	scaling->matrix[1][1] = v->y;
	scaling->matrix[2][2] = v->z;
	return (scaling);
}

t_matrix	*rotation_matrix_x(float angle)
{
	t_matrix	*rotation;

	rotation = create_matrix(4, 4);
	set_to_indentity(rotation);
	rotation->matrix[1][1] = cosf(angle);
	rotation->matrix[1][2] = -sinf(angle);
	rotation->matrix[2][1] = sinf(angle);
	rotation->matrix[2][2] = cosf(angle);
	return (rotation);
}

t_matrix	*rotation_matrix_y(float angle)
{
	t_matrix	*rotation;

	rotation = create_matrix(4, 4);
	set_to_indentity(rotation);
	rotation->matrix[0][0] = cosf(angle);
	rotation->matrix[0][2] = sinf(angle);
	rotation->matrix[2][0] = -sinf(angle);
	rotation->matrix[2][2] = cosf(angle);
	return (rotation);
}

t_matrix	*rotation_matrix_z(float angle)
{
	t_matrix	*rotation;

	rotation = create_matrix(4, 4);
	set_to_indentity(rotation);
	rotation->matrix[0][0] = cosf(angle);
	rotation->matrix[0][1] = -sinf(angle);
	rotation->matrix[1][0] = sinf(angle);
	rotation->matrix[1][1] = cosf(angle);
	return (rotation);
}
