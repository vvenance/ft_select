#include "../inc/ft_select.h"

static void norme_upkey(t_dclist *ptr, t_dclist *tmp, t_info *info)
{
	tmp->know[CURR] = 0;
	tputs(tgoto(tgetstr("cm", NULL), tmp->know[POSX], tmp->know[POSY]),
		1, &my_putc);
	show_with_attr(tmp, info);
	ptr->know[CURR] = 1;
	tputs(tgoto(tgetstr("cm", NULL), ptr->know[POSX], ptr->know[POSY]),
		1, &my_putc);
	show_with_attr(ptr, info);
}

void	up_key(t_dclist *list, t_info *info)
{
	t_dclist	*ptr;
	t_dclist	*tmp;
	int			i;

	ptr = list;
	while (!ptr->know[CURR])
		ptr = ptr->next;
	tmp = ptr;
	i = info->elem_per_col;
	while (i)
	{
		ptr = ptr->prev;
		if (ptr == list)
		{
			if (i == 1)
				i--;
			break;
		}
		i--;
	}
	if (!i)
		norme_upkey(ptr, tmp, info);
}

static void norme_downkey(t_dclist *ptr, t_dclist *tmp, t_info *info)
{
	tmp->know[CURR] = 0;
	tputs(tgoto(tgetstr("cm", NULL), tmp->know[POSX], tmp->know[POSY]),
		1, &my_putc);
	show_with_attr(tmp, info);
	ptr->know[CURR] = 1;
	tputs(tgoto(tgetstr("cm", NULL), ptr->know[POSX], ptr->know[POSY]),
		1, &my_putc);
	show_with_attr(ptr, info);
}

void	down_key(t_dclist *list, t_info *info)
{
	t_dclist	*ptr;
	t_dclist	*tmp;
	int			i;

	ptr = list;
	while (!ptr->know[CURR])
		ptr = ptr->next;
	tmp = ptr;
	i = info->elem_per_col;
	while (i)
	{
		ptr = ptr->next;
		if (ptr == list)
		{
			if (i == 1)
				i--;
			break;
		}
		i--;
	}
	if (!i)
		norme_downkey(ptr, tmp, info);
}