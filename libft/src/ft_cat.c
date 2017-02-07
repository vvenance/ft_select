/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:45:32 by vvenance          #+#    #+#             */
/*   Updated: 2016/06/08 11:45:37 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"
#define BUF_SIZE 30000

int		ft_cat(int fd)
{
	int		i;
	int		ret;
	char	buf[BUF_SIZE + 1];

	i = 0;
	while (0 != (ret = (read(fd, buf, BUF_SIZE))))
	{
		if (ret == -1)
		{
			close(fd);
			return (-1);
		}
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	close(fd);
	return (0);
}
