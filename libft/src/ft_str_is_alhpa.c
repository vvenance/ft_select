/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alhpa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:23:00 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:23:03 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	if (!str[i])
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]))
			i++;
		else
			return (0);
	}
	if (i)
		return (1);
	return (0);
}
