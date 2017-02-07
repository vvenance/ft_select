/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:25:04 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:25:07 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstsize;
	size_t srcsize;
	size_t i;
	size_t j;

	dstsize = 0;
	srcsize = ft_strlen(src);
	while (dst[dstsize] != '\0')
	{
		if (dstsize == size)
			return (dstsize + srcsize);
		dstsize++;
	}
	if (dstsize < size)
	{
		i = dstsize;
		j = 0;
		while (src[j] != '\0' && j < (size - dstsize - 1))
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (dstsize + srcsize);
}
