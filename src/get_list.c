#include "../inc/ft_select.h"

void	get_list(char **av, t_dclist **list, t_info *info)
{
	int i;

	i = 0;
	info->nb_elem = 0;
	info->name_maxlen = 0;
	while (av[++i])
	{
		add_elem_dcl(list, av[i]);
		info->nb_elem++;
		if ((int)ft_strlen(av[i]) > info->name_maxlen)
			info->name_maxlen = ft_strlen(av[i]);
	}
	(*list)->know[CURR] = 1;
}

void	re_get_list(t_dclist *list, t_info *info)
{
	t_dclist *ptr;

	info->nb_elem = 0;
	info->name_maxlen = 0;
	ptr = list;
	while (ptr)
	{
		ptr = ptr->next;
		info->nb_elem++;
		if (ptr->know[NAMLEN] > info->name_maxlen)
			info->name_maxlen = ptr->know[NAMLEN];
		if (ptr == list)
			break;
	}
}