/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:19:22 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:19:25 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*tmp;

	if (!dst || !src || n == 0)
		return (dst);
	tmp = ft_strnew(n + 1);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dst, tmp, n);
	return (dst);
}
