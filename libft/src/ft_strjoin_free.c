/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:09:01 by vvenance          #+#    #+#             */
/*   Updated: 2016/11/14 18:09:03 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	int		i;
	int		iparam;
	char	*str;

	i = 0;
	iparam = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = _MALLOCC(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	while (s1[iparam] != '\0')
	{
		str[i++] = s1[iparam];
		iparam++;
	}
	iparam = 0;
	while (s2[iparam] != '\0')
	{
		str[i] = s2[iparam];
		i++;
		iparam++;
	}
	free((void *)(s1));
	str[i] = '\0';
	return (str);
}
