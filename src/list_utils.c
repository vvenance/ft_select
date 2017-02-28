#include "../inc/ft_select.h"

static char	**get_names(char **name, char *str)
{
	name = NULL;
	name = malloc(5 * sizeof(char *));
	if (!name)
		exit (0);
	name[CLASSIC] = ft_strjoin("\E[0m", str);
	name[REVV] = ft_strjoin("\E[0;7m", str);
	name[UNDERL] = ft_strjoin("\E[0;4m", str);
	name[BOTH] = ft_strjoin("\E[0;4;7m", str);
	name[SIMPLE] = ft_strdup(str);
	return (name);
}

static void	get_eleminfo(int *know, int len)
{
	know[POSX] = -1;
	know[POSY] = -1;
	know[SELECT] = 0;
	know[CURR] = 0;
	know[NAMLEN] = len;
}

void		add_elem_dcl(t_dclist **list, char *str)
{
	t_dclist	*new;
	t_dclist	*tmp;

	tmp = *list;
	new = NULL;
	while (tmp && tmp->next != *list)
		tmp = tmp->next;
	if (!(new = malloc(sizeof(t_dclist))))
		exit(0);
	new->name = get_names(new->name, str);
	get_eleminfo(new->know, ft_strlen(str));
	if (tmp)
	{
		new->prev =	tmp;
		new->next = tmp->next;
		tmp->next->prev = new;
		tmp->next = new;
	}
	else
	{
		tmp = new;
		tmp->prev = new;
		tmp->next = new;
		*list = tmp;
	}
}

void	del_elem_dcl(t_dclist **list, t_dclist *elem)
{
	if (elem != *list)
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
	}
	// ft_free(6, &elem->name[0], &elem->name[1], &elem->name[2], &elem->name[3],
	// 	&elem->name, &elem);
}