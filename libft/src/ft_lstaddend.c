/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:16:20 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:16:24 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return (0);
	if (!(*alst))
	{
		*alst = new;
		return (1);
	}
	temp = *alst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (1);
}
