#include "../inc/ft_select.h"

void	add_entry(t_entry **list, char *entry)
{
	t_entry	*new;
	t_entry	*tmp;

	tmp = *list;
	new = NULL;
	while (tmp && tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_entry));
	new.selected = 0;
	if (tmp)
	{
		tmp->next = new;
		new->prev = tmp;
		new->next = *list;
	}
	else
	{
		tmp = new;
		tmp->prev = NULL;
		tmp->next = NULL;
	}
}

void	del_entry(t_entry **list, t_entry *elem)
{
	t_entry *tmp;
	t_entry	*prev;

	tmp = *list;
	prev = NULL;
	if (tmp->next == tmp)
	{
		*list = NULL;
		tmp = NULL;
	}
	while (tmp && ft_strcmp(tmp->name, elem->name))
		tmp = tmp->next;
	prev = tmp->prev;
	prev->next = tmp->next;
	ft_free(2, &elem->name, &elem);

}