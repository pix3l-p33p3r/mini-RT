/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:39 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/27 13:56:22 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "../main.h"
# include <ctype.h>

typedef struct s_elem
{
	char	*line;
	int		index;
	int		count[3];
	int		fd;
}	t_elem;

t_vector	parse_vector(char *str, int *j);
void		check_element(char *str);
char		*ft_strchr2(char *s, int c);
void		read_scenes(char *filename, t_vars *var);
int			skip_space(char *str, int i);
void		check_numbers(float num, float min, float max);
float		atoi_int(char *str, int *i, int *sign, float res);
float		atoi_float(char *str, int *i, float res);
float		parse_number(char *str, int *j);
void		add_object(t_vars *var, t_object obj);
void		check_ambient_lightning(t_vars *var, char *line, int i);
void		check_camera(t_vars *var, char *line, int i);
void		check_light(t_vars *var, char *line, int i);
void		check_sphere(t_vars *var, char *line, int i);
void		check_plane(t_vars *var, char *line, int i);
void		check_cylinder(t_vars *var, char *line, int i);
void		check_all_scenes(t_vars *var, char *line, int i);
void		ft_free(t_object **s);
int			skip_space(char *str, int i);
int			indexation(char *line, int index);
int			check_extention(char *str);
void		duplicate_error(char *line, int fd);
void		init_vars(t_elem *elem, char *str);
void		missing_check(t_elem *elem);

#endif
