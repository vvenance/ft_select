/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:23:44 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:23:50 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	endchar;
	int i;

	endchar = 0;
	i = 0;
	while (s1[endchar] != '\0')
	{
		endchar++;
	}
	while (s2[i] != '\0')
	{
		s1[endchar] = s2[i];
		endchar++;
		i++;
	}
	s1[endchar] = '\0';
	return (s1);
}
