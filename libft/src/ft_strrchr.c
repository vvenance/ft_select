/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:26:37 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:26:40 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *save;

	save = (char *)0;
	while (1)
	{
		if (*s == c)
			save = (char *)s;
		if (*s++ == 0)
			break ;
	}
	return (save);
}
