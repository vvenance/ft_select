/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:28:41 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:29:00 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(wchar_t *chr)
{
	int		res;

	res = 0;
	while (*chr)
	{
		if (*chr <= 0x7F)
		{
			if ((*chr >= 1 && *chr <= 32) || *chr == 127)
				res += 3;
			res += 1;
		}
		else if (*chr <= 0x7FF)
			res += 2;
		else if (*chr <= 0xFFFF)
			res += 3;
		else if (*chr <= 0x10FFFF)
			res += 4;
		chr++;
	}
	return (res);
}
