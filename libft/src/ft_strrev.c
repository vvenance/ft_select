/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:26:45 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:26:49 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*tmp;
	int		length;
	int		i;
	char	c_tmp;

	tmp = str;
	length = 0;
	while (*tmp)
	{
		length++;
		tmp++;
	}
	i = 0;
	while (i < (length / 2))
	{
		c_tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = c_tmp;
		i++;
	}
	return (str);
}
