/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:13:56 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:14:01 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenofn(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

static char	*do_itoa(char *str, int n, int len)
{
	int		i;

	i = 1;
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[len - i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	str[len - i] = (n % 10) + 48;
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = lenofn(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_strnew(len);
	if (str)
		str = do_itoa(str, n, len);
	return (str);
}
