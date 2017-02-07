/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:55:18 by vvenance          #+#    #+#             */
/*   Updated: 2017/02/05 15:13:23 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	static t_save	save;
	int				ret;
	char			buf[BUFF_SIZE + 1];

	if (BUFF_SIZE < 1 || fd < 0)
		return (-1);
	if (!save.save)
		save.save = NULL;
	ft_memset(buf, '\0', BUFF_SIZE + 1);
	save.fd = fd;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && buf[0] != '\n')
	{
		if (!save.save)
			save.save = ft_strdup(buf);
		else
			save.save = ft_strjoin_free(save.save, buf);
		ft_memset(buf, '\0', BUFF_SIZE + 1);
	}
	*line = ft_strdup(save.save);
	free((void *)(save.save));
	save.save = NULL;
	return (1);
}
