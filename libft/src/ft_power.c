/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:19:49 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:19:55 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_power(long double x, long double y)
{
	long double	res;
	int			neg;

	res = x;
	neg = (y < 0) ? 1 : 0;
	if (neg)
		y *= -1;
	if (!y)
		return (1);
	while (--y > 0)
		res *= x;
	if (neg)
		res = 1 / res;
	return (res);
}
