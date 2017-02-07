/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:11:34 by vvenance          #+#    #+#             */
/*   Updated: 2016/11/30 18:11:46 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(int nb, ...)
{
	va_list	ap;
	void	**tmp;

	va_start(ap, nb);
	while (nb--)
	{
		if ((tmp = va_arg(ap, void **)))
		{
			free(*tmp);
			*tmp = NULL;
		}
	}
	va_end(ap);
}
