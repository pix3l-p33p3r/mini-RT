/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myatoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 01:22:31 by hchaguer          #+#    #+#             */
/*   Updated: 2023/12/27 01:37:38 by elel-yak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	atoi_int(char *str, int *i, int *sign, float res)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	res = 0;
	while (str && isdigit(str[*i]))
	{
		res = 10 * res + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}

float	atoi_float(char *str, int *i, float res)
{
	int	pres;

	pres = 10;
	while (str && isdigit(str[*i]))
	{
		res = res + (float)(str[*i] - '0') / pres;
		(*i)++;
		pres *= 10;
	}
	return (res);
}
