/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:18:38 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:18:43 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ds;
	char			*sr;
	size_t			i;

	i = 0;
	sr = (char *)(src);
	ds = dst;
	while (i < n)
	{
		ds[i] = sr[i];
		if (sr[i] == c)
			return (&ds[i + 1]);
		i++;
	}
	return (NULL);
}
