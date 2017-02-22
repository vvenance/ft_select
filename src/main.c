#include "../inc/ft_select.h"

int		my_putc(int c)
{
	write(isatty(1), &c, 1);
	return (0);
}

void	clear_term_get_size(t_info *info)
{
	struct winsize	winsize;
	char			*str;

	str = tgetstr("cl", NULL);
	tputs(str, 0, &my_putc);
	ioctl(0, TIOCGWINSZ, &winsize);
	info->tcol = winsize.ws_col;
	info->tline = winsize.ws_row;
	info->elem_per_col = info->tcol / (info->name_maxlen + 1);
	info->nb_lines = info->nb_elem / info->elem_per_col;
	if (info->nb_elem % info->elem_per_col)
		info->nb_lines += 1;
	tputs(tgoto(tgetstr("vi", NULL), 0, 0), 1, &my_putc);
}

void	get_coor(t_dclist *ptr)
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
	ptr->know[POSY] = ft_atoi(array[0]);
	ptr->know[POSX] = ft_atoi(array[1]);
	ft_free_tab(array);
}

void	show_with_attr(t_dclist *ptr, t_info *info)
{
	int i;

	get_coor(ptr);
	if (!ptr->know[SELECT] && !ptr->know[CURR])
		ft_putstr_fd(ptr->name[CLASSIC], 2);
	else if (ptr->know[SELECT] && !ptr->know[CURR])
		ft_putstr_fd(ptr->name[REVV], 2);
	else if (!ptr->know[SELECT] && ptr->know[CURR])
	{
		ft_putendl("yolo");
		ft_putstr_fd(ptr->name[UNDERL], 2);
		ft_putendl("yolo");
	}
	else if (ptr->know[SELECT] && ptr->know[CURR])
		ft_putstr_fd(ptr->name[BOTH], 2);
	i = (info->name_maxlen - ptr->know[NAMLEN]) + 1;
}

void	show(t_info *info, t_dclist *list)
{
	t_dclist	*ptr;
	int			i;
	int			cnt;

	ptr = list;
	i = 0;
	cnt = 0;
	while (ptr)
	{
		if (!cnt)
			cnt = info->elem_per_col;
		show_with_attr(ptr, info);
		if (cnt >= 1 && ptr->next != list)
			ft_putstr_fd("\E[0m ", 2);
		else if (cnt == 1 && ptr->next != list)
			ft_putendl_fd("\E[0m", 2);
		cnt--;
		ptr = ptr->next;
		if (ptr == list)
			break;
	}
	// int able;
	// int d;
	// t_dclist *ptr;

	// ptr = list;
	// d = 0;
	// able = info->tcol / (info->name_maxlen + 1);
	// while (ptr)
	// {
	// 	if (!d)
	// 		d = able;
	// 	ft_putstr(ptr->name);
	// 	if (d >= 1 && ptr->next != list)
	// 		ft_putchar(' ');
	// 	else if (d == 1 && ptr->next != list)
	// 		ft_putendl("");
	// 	d--;
	// 	ptr = ptr->next;
	// 	if (ptr == list)
	// 		break;
	// }
}

void	get_key(char *buff, t_dclist *list, t_info *info)
{
	//printf("buf0 = %d buf1= %d buf2= %d buf3 = %d\n", (int)buff[0], (int)buff[1], (int)buff[2], (int)buff[3]); //affiche les codes des touches
	if (buff[0] == 4) //ctrl+d
		exit (0); // free les malloc et quitter proprement
	else if (buff[0] == 27 && buff[1] == 0)
		ft_putendl("echap");
	else if (buff[0] == 32)
		ft_putendl("espace");
	else if (buff[0] == 8)
		ft_putendl("backspace");
	else if (buff[0] == 127)
		ft_putendl("delete");
	else if (buff[0] == 10 && buff[1] == 0)
		ft_putendl("return");
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 65)
		ft_putendl("\E[0;4;7mfleche du haut");
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 66)
		ft_putendl("\E[0mfleche du bas");
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
		tputs(tgoto(tgetstr("vi", NULL), 1, 0), 1, &my_putc);
	else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
		ft_putendl("fleche du gauche");
	else if (buff[0] == 26)
		ft_putendl("ctrl+z");
	ft_bzero(buff, 3);
}

int main(int ac, char **av)
{
	t_dclist		*list;
	t_info			info;
	struct termios	term;
	struct termios	config;
	char			buff[4];

	list = NULL;
	if (ac < 2)
		ft_putendl_fd("Usage: ./ft_select [arglist ...].", 2);
	else if (av[1] && getenv("TERM") != NULL && (init_termcaps(&term, &config)))
	{
		get_list(av, &list, &info);
		clear_term_get_size(&info);
		open(0, O_RDONLY);
		show(&info, list);
		while (1)
		{
			read(0, buff, 3);
			get_key(buff, list, &info);
		}
		//return_to_term(&config);
	}
	else
		ft_putendl_fd("Something went wrong. Maybe you should set a correct environnement before running the program again. Bye !", 2);
	return_to_term(&config);
	return (0);
}