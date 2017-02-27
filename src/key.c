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
		del_elem_dcl(&list, ptr);
		return_to_term(&config);
		exit(0);
	}
	ptr = list;
	while (!ptr->know[CURR])
		ptr = ptr->next;
	ptr->next->know[CURR] = 1;
	del_elem_dcl(&list, ptr);
	re_get_list(list, info);
	clear_term_get_size(info);
	show(info, list);

}