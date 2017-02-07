/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:44:56 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 11:45:06 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (str[i] == '\033')
		return (0);
	while ((str[i] > 0 && str[i] <= 32) || str[i] == 127)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (k != 0)
			k = k * 10;
		k = k + str[i] - '0';
		i++;
	}
	i--;
	while (ft_isdigit(str[i]) && i >= 0)
		i--;
	if (str[i] == '-')
		return (-k);
	return (k);
}
