/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:08:19 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/27 14:14:45 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	indexation(char *line, int index)
{
	index = 0;
	if (line[0] == 'A')
		index = 0;
	else if (line[0] == 'C')
		index = 1;
	else if (line[0] == 'L')
		index = 2;
	return (index);
}

void	duplicate_error(char *line, int fd)
{
	printf("Parsing Error : duplicate\n");
	free(line);
	close(fd);
	exit(EXIT_FAILURE);
}

void	init_vars(t_elem *elem, char *str)
{
	elem->count[0] = 0;
	elem->count[1] = 0;
	elem->count[2] = 0;
	elem->fd = open(str, O_RDONLY);
}

void	missing_check(t_elem *elem)
{
	if (!(elem->count[0] == 1 && elem->count[1] == 1))
	{
		printf("Parsing Error : missing Element\n");
		exit(EXIT_FAILURE);
	}
}
