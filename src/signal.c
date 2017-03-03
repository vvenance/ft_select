#include "../inc/ft_select.h"

extern t_dclist 		*list;
extern t_info			info;
extern struct termios	config;

static void	my_sigwinch(int signum)
{
	if (signum == SIGWINCH || signum == SIGCONT)
		clear_term_get_size(&info, list);
}

static void	my_sigtstp(int signum)
{
	ft_putendl("here");
	if (signum == SIGTSTP || signum == SIGINT || signum == SIGQUIT)
	{
		//free list
		return_to_term(&config);
		exit(0);
	}
}

void	ft_signal(void)
{
	signal(SIGWINCH, &my_sigwinch);
	signal(SIGTSTP, &my_sigtstp);
	signal(SIGCONT, &my_sigwinch);
	signal(SIGINT, &my_sigtstp);
	signal(SIGQUIT, &my_sigtstp);
}