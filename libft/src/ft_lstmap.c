/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:17:42 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:18:00 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*keep;
	t_list	*new;

	new = f(ft_lstnew(lst->content, lst->content_size));
	keep = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = f(ft_lstnew(lst->content, lst->content_size));
		new = new->next;
	}
	return (keep);
}
