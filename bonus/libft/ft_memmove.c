/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:37:57 by hchaguer          #+#    #+#             */
/*   Updated: 2022/10/28 17:24:27 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		while (i <= len)
		{
			((unsigned char *)dst)[len - i] = ((unsigned char *)src)[len - i];
			i++;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
