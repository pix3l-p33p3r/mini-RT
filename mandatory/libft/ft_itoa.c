/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:52:26 by hchaguer          #+#    #+#             */
/*   Updated: 2022/10/27 21:09:32 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		i;
	char		*str;
	long int	ln;

	i = ft_count(n);
	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		i++;
	}
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i)
	{
		i--;
		str[i] = ln % 10 + '0';
		ln /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
