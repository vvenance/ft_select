/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:20:01 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:20:26 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putaddr(void *addr)
{
	long int			base;
	char				c;
	unsigned long int	n;

	n = (unsigned long int)addr;
	base = 16;
	write(1, "0x", 2);
	while (n / base >= 16)
		base *= 16;
	while (base > 0)
	{
		c = '0' + n / base;
		if (c > '9')
		{
			c += 39;
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		n %= base;
		base /= 16;
	}
}
