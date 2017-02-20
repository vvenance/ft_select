#include "../inc/ft_select.h"

void return_to_term(struct termios *config)
{
	if (tcgetattr(0, config) != -1)
		exit(1);
}

void	clear_term_get_size(t_info *info)
{
	struct winsize	winsize;
	char			*str;

	str = tgetstr("cl", NULL);
	fputs(str, stdout);
	ioctl(0, TIOCGWINSZ, &winsize);
	info->tcol = winsize.ws_col;
	info->tline = winsize.ws_row;
}

void	show(t_info *info, t_dclist *list)
{
	int able;
	int d;
	t_dclist *ptr;

	ptr = list;
	d = 0;
	able = info->tcol / (info->name_maxlen + 1);
	while (ptr)
	{
		if (!d)
			d = able;
		ft_putstr(ptr->name);
		if (d >= 1 && ptr->next != list)
			ft_putchar(' ');
		else if (d == 1 && ptr->next != list)
			ft_putendl("");
		d--;
		ptr = ptr->next;
		if (ptr == list)
			break;
	}
}

int main(int ac, char **av)
{
	t_dclist		*list;
	t_info			info;
	struct termios	term;
	struct termios	config;

	list = NULL;
	if (ac < 2)
		ft_putendl_fd("Usage: ./ft_select [arglist ...].", 2);
	if (av[1] && getenv("TERM") != NULL && (init_termcaps(&term, &config)))
	{
		get_list(av, &list, &info);
		//while (list)
		//{
			clear_term_get_size(&info);
			show(&info, list);
			return_to_term(&config);
		//}
	}
	return (0);
}