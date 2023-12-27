/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:01:53 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/27 16:48:55 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	parse_number(char *str, int *j)
{
	float	res;
	int		i;
	int		sign;

	sign = 1;
	res = 0;
	i = skip_space(str, *j);
	res = atoi_int(str, &i, &sign, res);
	if (str[i] == '.')
		i++;
	res = atoi_float(str, &i, res);
	i = skip_space(str, i);
	*j = i;
	return (sign * res);
}

t_vector	parse_vector(char *str, int *j)
{
	t_vector	res;

	res.x = parse_number(str, j);
	if (str[*j] != ',')
	{
		printf("Parsing Error : missing commaz\n");
		exit(EXIT_FAILURE);
	}
	(*j)++;
	res.y = parse_number(str, j);
	if (str[*j] != ',')
	{
		printf("Parsing Error : missing comma\n");
		exit(EXIT_FAILURE);
	}
	(*j)++;
	res.z = parse_number(str, j);
	return (res);
}

void	add_object(t_vars *var, t_object obj)
{
	t_object	*tmp;

	var->objects[var->pos] = obj;
	var->pos++;
	if (var->pos + 1 == var->len)
	{
		tmp = ft_calloc(var->len * 2 + 1, sizeof(t_object));
		ft_memcpy(tmp, var->objects, var->len * sizeof(t_object));
		free(var->objects);
		var->objects = tmp;
		var->len = var->len * 2;
	}
}

void	read_scenes(char *filename, t_vars *var)
{
	char	*line;
	int		fd;
	int		i;

	(void)var;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Parsing Error : file descriptor failed\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '#')
		{
			free (line);
			continue ;
		}
		i = skip_space(line, 0);
		check_all_scenes(var, line, i);
	}
}

void	check_element(char *str)
{
	t_elem	elem;
	int		i;

	i = 0;
	init_vars(&elem, str);
	while (1)
	{
		elem.line = get_next_line(elem.fd);
		if (!elem.line)
			break ;
		if (elem.line[0] == 'A' || elem.line[0] == 'C' || elem.line[0] == 'L')
		{
			elem.index = indexation(elem.line, elem.index);
			if (elem.count[elem.index] == 1)
				duplicate_error(elem.line, elem.fd);
			elem.count[elem.index]++;
			free(elem.line);
		}
		else
			free(elem.line);
	}
	missing_check(&elem);
}
