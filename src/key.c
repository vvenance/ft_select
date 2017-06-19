#include "../inc/ft_select.h"

void	space_key(t_dclist *list, t_info *info)
{
	t_dclist *ptr;

	ptr = list;
	while (!ptr->know[CURR])
		ptr = ptr->next;
	if (ptr->know[SELECT])
	{
		ptr->know[SELECT] = 0;
		tputs(tgoto(tgetstr("cm", NULL), ptr->know[POSX], ptr->know[POSY]),
			1, &my_putc);
		show_with_attr(ptr, info);
	}
	else
	{
		ptr->know[SELECT] = 1;
		ptr->know[CURR] = 0;
		tputs(tgoto(tgetstr("cm", NULL), ptr->know[POSX], ptr->know[POSY]),
			1, &my_putc);
		show_with_attr(ptr, info);
		ptr->next->know[CURR] = 1;
		tputs(tgoto(tgetstr("cm", NULL), ptr->next->know[POSX],
			ptr->next->know[POSY]), 1, &my_putc);
		show_with_attr(ptr->next, info);
	}
}

void	right_key(t_dclist *list, t_info *info)
{
	t_dclist *ptr;

	ptr = list;
	while (!ptr->know[CURR])
		ptr = ptr->next;
	ptr->know[CURR] = 0;
	tputs(tgoto(tgetstr("cm", NULL), ptr->know[POSX], ptr->know[POSY]),
			1, &my_putc);
	show_with_attr(ptr, info);
	ptr->next->know[CURR] = 1;
	tputs(tgoto(tgetstr("cm", NULL), ptr->next->know[POSX],
		ptr->next->know[POSY]), 1, &my_putc);
	show_with_attr(ptr->next, info);
}

void	left_key(t_dclist *list, t_info *info)
{
	t_dclist *ptr;

	ptr = list;
	while (!ptr->know[CURR])
		ptr = ptr->next;
	ptr->know[CURR] = 0;
	tputs(tgoto(tgetstr("cm", NULL), ptr->know[POSX], ptr->know[POSY]),
			1, &my_putc);
	show_with_attr(ptr, info);
	ptr->prev->know[CURR] = 1;
	tputs(tgoto(tgetstr("cm", NULL), ptr->prev->know[POSX],
		ptr->prev->know[POSY]), 1, &my_putc);
	show_with_attr(ptr->prev, info);
}

void	bspace_delete_key(t_dclist *list, t_info *info, struct termios config)
{
	t_dclist *ptr;

	if (info->nb_elem == 1)
	{
		//free_le ptr sur la liste
		return_key(list, config);
	}
	ptr = list;
	while (!ptr->know[CURR])
		ptr = ptr->next;
	ptr->next->know[CURR] = 1;
	if (ptr == list)
		*list = *list->next;
	del_elem_dcl(&list, ptr);
	re_get_list(list, info);
	clear_term_get_size(info,list);
}

void	return_key(t_dclist *list, struct termios config)
{
	t_dclist *ptr;
	int ret;
	int fd;
	char *str;

	ptr = list;
	ret = 0;
	fd = open("/dev/tty", O_APPEND);
	ft_putstr_fd("\033[?1049l", 2);
	while (ptr)
	{
		if (ptr->know[SELECT] == 1)
		{
			if (!ret)
			{
				ft_putstr_fd(ptr->name[SIMPLE], fd);
				ret += 1;
			}
			else
			{
				ft_putchar_fd(' ', fd);
				ft_putstr_fd(ptr->name[SIMPLE], fd);
			}
		}
		ptr = ptr->next;
		if (ptr->prev != list)
			;//free !
		if (ptr == list)
			break;
	}
	//free list
	//return_to_term(&config);
	str = tgetstr("cnorm", NULL);
	tputs(str, 0, &my_putc);
	str = tgetstr("ve", NULL);
	tputs(str, 0, &my_putc);
	if (tcgetattr(0, &config) != -1)
		exit(1);
	exit(0);
}