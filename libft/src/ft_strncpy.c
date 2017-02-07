/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:26:06 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:26:10 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *s;

	s = dst;
	while (n > 0 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		--n;
	}
	while (n > 0)
	{
		*dst = '\0';
		dst++;
		--n;
	}
	return (s);
}
