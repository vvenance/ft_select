/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:27:33 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:27:36 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	if (!s)
		return (NULL);
	if (!*s)
		return ((char *)s);
	j = ft_strlen((char *)s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
			&& j > i)
		j--;
	return (ft_strsub(s, i, j - i + 1));
}
