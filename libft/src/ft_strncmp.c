/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:25:59 by vvenance          #+#    #+#             */
/*   Updated: 2016/12/16 10:58:18 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (((s1[i] || s2[i])) && (i < n))
	{
		if (s1[i] != s2[i])
			return (ft_strcmp(s1, s2));
		i++;
	}
	return (0);
}
