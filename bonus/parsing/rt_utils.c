/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <hchaguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 22:33:56 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/27 17:50:26 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	whitespaces(char str)
{
	while (str == ' ' || (str >= 9 && str <= 13))
		return (1);
	return (0);
}

int	skip_space(char *str, int i)
{
	while (str && whitespaces(str[i]))
		i++;
	return (i);
}

void	check_numbers(float num, float min, float max)
{
	if (num < min || num > max)
	{
		printf("Parsing Error : unexpected number\n");
		exit(EXIT_FAILURE);
	}
}

int	check_extention(char *str)
{
	if (!(strchr(str, '.')))
		return (1);
	if (strncmp(strchr(str, '.'), ".rt", 4) != 0)
		return (1);
	return (0);
}

void	unexpected_error(char *line, int i)
{
	printf("Error: unexpected %c\n", line[i]);
	exit(EXIT_FAILURE);
}
