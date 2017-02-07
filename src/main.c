#include "../inc/ft_select.h"

int main(int ac, char **av)
{
	t_dclist		*list;
	t_info			info;
	struct termios	term;
	struct termios	config;

	list = NULL;
	term = NULL;
	if (av[1] && getenv("TERM") != NULL && (init_termcaps(&term, &config)))
	{
		get_list(av, &list, &info);
		

	}
	return (0);
}