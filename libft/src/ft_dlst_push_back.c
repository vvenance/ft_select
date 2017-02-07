/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:46:27 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 11:46:31 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist			*ft_dlst_push_back(t_dlist *list, t_node *new)
{
	if (list != NULL)
	{
		if (list->last == NULL)
		{
			new->prev = NULL;
			list->first = new;
			list->last = new;
		}
		else
		{
			list->last->next = new;
			new->prev = list->last;
			list->last = new;
		}
		list->lenght++;
	}
	return (list);
}
