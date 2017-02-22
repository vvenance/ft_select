#include "../inc/ft_select.h"

void	add_elem_dcl(t_dclist **list, char *name)
{
	t_dclist	*new;
	t_dclist	*tmp;

	tmp = *list;
	new = NULL;
	while (tmp && tmp->next != *list)
		tmp = tmp->next;
	if (!(new = malloc(sizeof(t_dclist))))
		exit(0);
	new->name = name;
	new->length = ft_strlen(name);
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
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	ft_free(2, &elem->name, &elem);
}

void return_to_term(struct termios *config)
{
	if (tcgetattr(0, config) != -1)
		exit(1);
}