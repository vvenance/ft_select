/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:46:40 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 11:46:43 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_find_next_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (2);
	while (i < nb / i || nb == 4)
	{
		if (nb % i == 0)
			return (ft_find_next_prime(nb + 1));
		else
			i++;
	}
	return (nb);
}
