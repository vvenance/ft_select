/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:26:25 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:26:29 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrev(char *c, const int len)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = len - 1;
	while (i < (len / 2))
	{
		tmp = c[i];
		c[i++] = c[j];
		c[j--] = tmp;
	}
	return (c);
}
