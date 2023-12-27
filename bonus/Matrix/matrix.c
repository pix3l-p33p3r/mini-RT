/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 06:13:00 by elel-yak          #+#    #+#             */
/*   Updated: 2023/12/26 20:58:21 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_to_indentity(t_matrix *mt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < mt->rows)
	{
		j = 0;
		while (j < mt->cols)
		{
			if (i == j)
				mt->matrix[i][j] = 1.0f;
			else
				mt->matrix[i][j] = 0.0f;
			j++;
		}
		i++;
	}
}

void	print_matrix(t_matrix *matrix)
{
	int	i;
	int	j;

	if (!matrix)
		return ;
	i = 0;
	printf("[ \n");
	while (i < matrix->rows)
	{
		j = 0;
		printf("\t[ ");
		while (j < matrix->cols)
		{
			printf(" %f  %c", matrix->matrix[i][j], ' ');
			j++;
		}
		printf("],\n");
		i++;
	}
	printf("]\n");
}

void	delete_matrix(t_matrix *_this)
{
	int	row_index;

	row_index = 0;
	if (_this)
	{
		if (_this->matrix)
		{
			while (row_index < _this->rows)
			{
				if (_this->matrix[row_index])
					free(_this->matrix[row_index]);
				row_index++;
			}
			free(_this->matrix);
		}
		free(_this);
	}
}
