/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:31:19 by hchaguer          #+#    #+#             */
/*   Updated: 2022/10/27 15:39:03 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	i = 0;
	if (!n || (s1 != NULL && s2 == s1))
		return (0);
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	while (ps1[i] == ps2[i] && i < n - 1)
		i++;
	return (ps1[i] - ps2[i]);
}
