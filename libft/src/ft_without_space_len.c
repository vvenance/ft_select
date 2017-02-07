/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_without_space_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:28:32 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:28:35 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_withoutspacelen(const char *str)
{
	unsigned int space_len;
	unsigned int len;
	unsigned int i;

	space_len = 0;
	i = 0;
	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		while (str[i])
			if (ft_isspace(str[i++]))
				space_len++;
	}
	return (len - space_len);
}
