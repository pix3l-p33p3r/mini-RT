/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 19:43:59 by hchaguer          #+#    #+#             */
/*   Updated: 2022/10/28 17:29:15 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, int len)
{
	size_t	i;
	char	*sub;
	char	*str;
	int		l;

	i = 0;
	l = ft_strlen(s);
	if (l <= len + (int)start)
		sub = malloc((l - start + 1) * sizeof(char));
	else
		sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	str = (char *)s;
	if (start >= ft_strlen(s))
	{
		sub[i] = '\0';
		return (sub);
	}
	ft_strlcpy(sub, (str + start), len + 1);
	return (sub);
}
