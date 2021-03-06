#include "../inc/ft_select.h"

t_dclist		*list;
t_info			info;
struct termios	config;
struct termios	term;

void	clear_term_get_size(t_info *info, t_dclist *list)
{
	struct winsize	winsize;
	char			*str;

	str = tgetstr("cl", NULL);
	tputs(str, 0, &my_putc);
	ioctl(0, TIOCGWINSZ, &winsize);
	info->tcol = winsize.ws_col;
	info->tline = winsize.ws_row;
	info->elem_per_col = info->tcol / (info->name_maxlen + 1);
	if (info->elem_per_col != 0)
	{
		info->nb_lines = info->nb_elem / info->elem_per_col;
		if (info->nb_elem % info->elem_per_col)
			info->nb_lines += 1;
		tputs(tgoto(tgetstr("vi", NULL), 0, 0), 1, &my_putc);
		if (info->nb_lines >= winsize.ws_row)
			ft_putstr_fd("The window is too small.", 2);
		else
			show(info, list);
	}
	else
		ft_putstr_fd("The window is too small.", 2);
}

void	get_key(char *buff, t_dclist *list, t_info *info, struct termios config)
{
	if (buff[0] == 4)
	{
		return_key(list, config);//return_to_term(&config);
		exit (0); // free les malloc et quitter proprement
	}
	else if (buff[0] == 27 && buff[1] == 0)
		ft_putendl("echap");
	else if (buff[0] == 32)
		space_key(list, info);
	else if (buff[0] == 8 || buff[0] == 127)
		bspace_delete_key(list, info, config);
	else if (buff[0] == 10 && buff[1] == 0)
		return_key(list, config);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		up_key(list, info);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		down_key(list, info);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		right_key(list, info);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		left_key(list, info);
	ft_bzero(buff, 3);
}

int main(int ac, char **av)
{
	char			buff[4];

	list = NULL;
	if (ac < 2)
		ft_putendl_fd("Usage: ./ft_select [arglist ...].", 2);
	else if (av[1] && getenv("TERM") != NULL && (init_termcaps(&term, &config)))
	{
		get_list(av, &list, &info);
		clear_term_get_size(&info, list);
		open(0, O_RDONLY);
		ft_signal();
		while (1)
		{
			read(0, buff, 3);
			get_key(buff, list, &info, config);
		}
	}
	else
	{
		ft_putendl_fd("Something went wrong. Maybe you should set an env before relauching", 2);
		sleep(3);
		return_key(list, config);
	}
	return (0);
}