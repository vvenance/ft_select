/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:22:19 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:22:21 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	int fact;

	fact = 0;
	if (nb == 1 || nb == 0)
	{
		fact = 1;
		return (fact);
	}
	else if (nb < 0 || nb > 12)
		return (0);
	else
	{
		fact = nb * ft_recursive_factorial(nb - 1);
		return (fact);
	}
}
