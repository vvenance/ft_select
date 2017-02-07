/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:27:08 by vvenance          #+#    #+#             */
/*   Updated: 2016/12/16 13:55:46 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_cnt(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (j == 1 && *s == c)
			j = 0;
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int	ft_len(const char *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb = ft_cnt((const char *)s, c);
	if (!(t = (char **)malloc(sizeof(*t) * (ft_cnt((const char *)s, c)) + 1)))
		return (NULL);
	while (nb--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(t[i] = ft_strsub((const char *)s, 0, ft_len((const char *)s, c))))
			return (NULL);
		s = s + ft_len(s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
