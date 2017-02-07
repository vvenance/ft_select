/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:19:38 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:19:42 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbword(const char *s, const char c)
{
	unsigned int count;
	unsigned int i;

	count = 0;
	if (s && c)
	{
		if (s[0] && s[0] != c)
			count = 1;
		else
			count = 0;
		i = 1;
		while (s[0] && s[i])
		{
			if (s[i - 1] == c && s[i] != c)
				count++;
			i++;
		}
	}
	return (count);
}
