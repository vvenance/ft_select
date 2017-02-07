/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:45:47 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 11:45:53 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist			*ft_create_list(void)
{
	t_dlist	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	else
	{
		new->first = NULL;
		new->last = NULL;
		new->lenght = 0;
	}
	return (new);
}
