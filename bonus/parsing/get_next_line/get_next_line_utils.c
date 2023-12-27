/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <hchaguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 01:56:56 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/12 11:50:46 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr1(char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (c == '\0')
		return (s + i);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (s + i);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy1(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
		n--;
	}
	return (dst);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*str;
	int		s1len;
	int		s2len;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	s1len = ft_strlen1(s1);
	s2len = ft_strlen1(s2);
	str = malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy1(str, s1, s1len);
	ft_memcpy1(str + s1len, s2, s2len);
	str[s1len + s2len] = '\0';
	free(s1);
	return (str);
}
