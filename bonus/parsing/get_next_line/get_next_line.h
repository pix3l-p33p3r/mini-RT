/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <hchaguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:54:12 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/12 11:50:23 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*ft_strchr1(char *s, int c);
char	*get_next_line(int fd);
char	*ft_getline(char *str, int fd);
char	*ft_strjoin1(char *s1, char *s2);
size_t	ft_strlen1(char *s);
char	*ft_setline(char *str);
char	*ft_savenextline(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
