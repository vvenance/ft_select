#include "../inc/ft_select.h"


static void	get_coor(t_dclist *ptr)
{
	char buff;
	char str[10];
	int j;
	char **array;

	ft_bzero(str, 9);
	ft_putstr("\E[6n");
	j = 0;
	while (1)
	{
		read(1, &buff, 1);
		if (buff == 'R')
			break;
		else if (ft_isdigit(buff) || buff == ';')
		{
			str[j] = buff;
			j++;
		}
	}
	array = ft_strsplit(str, ';');
	ptr->know[POSX] = ft_atoi(array[1]) - 1;
	ptr->know[POSY] = ft_atoi(array[0]) - 1;
	ft_free_tab(array);
}

void	show_with_attr(t_dclist *ptr, t_info *info)
{
	int i;

	if (!ptr->know[SELECT] && !ptr->know[CURR])
		ft_putstr_fd(ptr->name[CLASSIC], 2);
	else if (ptr->know[SELECT] && !ptr->know[CURR])
		ft_putstr_fd(ptr->name[REVV], 2);
	else if (!ptr->know[SELECT] && ptr->know[CURR])
		ft_putstr_fd(ptr->name[UNDERL], 2);
	else if (ptr->know[SELECT] && ptr->know[CURR])
		ft_putstr_fd(ptr->name[BOTH], 2);
	i = (info->name_maxlen - ptr->know[NAMLEN]) + 1;
	while (--i)
		ft_putstr_fd("\E[0m ", 2);
}

void	show(t_info *info, t_dclist *list)
{
	t_dclist	*ptr;
	int			cnt;

	ptr = list;
	cnt = 0;
	while (ptr)
	{
		if (!cnt)
			cnt = info->elem_per_col;
		get_coor(ptr);
		show_with_attr(ptr, info);
		if (cnt > 1 && ptr->next != list)
			ft_putstr_fd("\E[0m ", 2);
		else if (cnt == 1 && ptr->next != list)
			ft_putendl_fd("\E[0m", 2);
		cnt--;
		ptr = ptr->next;
		if (ptr == list)
			break;
	}
}