#include "../inc/ft_select.h"

void	get_list(char **av, t_dclist **list, t_info *info)
{
	int i;
	int	ret;

	i = 0;
	info->nb_elem = 0;
	info->name_maxlen = 0;
	while (av[++i])
	{
		add_elem_dcl(list, ft_strdup(av[i]));
		info->nb_elem++;
		if ((ret = ft_strlen(av[i])) > info->nb_elem)
			info->nb_elem = ret;
	}
}