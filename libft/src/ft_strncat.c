/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:25:36 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:25:55 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	endchar;
	int	i;

	endchar = 0;
	i = 0;
	while (s1[endchar] != '\0')
		endchar++;
	while (n)
	{
		s1[endchar] = s2[i];
		endchar++;
		i++;
		n--;
	}
	s1[endchar] = '\0';
	return (s1);
}
