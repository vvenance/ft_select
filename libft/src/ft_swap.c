/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 13:27:54 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 13:27:58 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap2(int *xdep, int *xfin, int *ydep, int *yfin)
{
	ft_swap(xdep, xfin);
	ft_swap(ydep, yfin);
}
