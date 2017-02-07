/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:18:48 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:18:51 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *data;

	data = (unsigned char *)s;
	while (n--)
	{
		if (*data == ((unsigned char)c))
			return (data);
		if (n)
			data++;
	}
	return (NULL);
}
