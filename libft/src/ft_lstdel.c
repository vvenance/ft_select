/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:16:37 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:16:41 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*bef;

	if (!alst || !del)
		return ;
	tmp = *alst;
	while (tmp->next != NULL)
	{
		del(tmp->content, tmp->content_size);
		bef = tmp;
		tmp = tmp->next;
		free(bef);
	}
	del(tmp->content, tmp->content_size);
	*alst = NULL;
}
