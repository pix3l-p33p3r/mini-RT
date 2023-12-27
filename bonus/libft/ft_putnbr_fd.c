/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchaguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 01:47:19 by hchaguer          #+#    #+#             */
/*   Updated: 2022/10/22 02:02:38 by hchaguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	ln;

	ln = n;
	if (ln < 0)
	{
		ft_putchar_fd ('-', fd);
		ln *= -1;
	}
	if (ln >= 10)
		ft_putnbr_fd ((ln / 10), fd);
	ft_putchar_fd ((ln % 10 + '0'), fd);
}
