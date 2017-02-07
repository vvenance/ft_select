/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:46:18 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 11:46:23 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node			*ft_create_node(void)
{
	t_node	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(*new));
	if (new != NULL)
	{
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}
