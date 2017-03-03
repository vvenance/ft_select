#include "../inc/ft_select.h"

extern t_dclist 			*list;
extern t_info			info;
extern struct termios	config;
extern struct termios	term;

static void	my_sigwinch(int signum)
{
	//char *tname;
	if (signum == SIGWINCH)
		clear_term_get_size(&info, list);
	if (signum == SIGCONT)
	{
		ft_putendl("here");
	// 	if ((tname = getenv("TERM")) != NULL && tgetent(NULL, tname) == 1
	// 	&& tcgetattr(0, &config) != ERR)
	// {
	// 	term = config;
	// 	term.c_cc[VMIN] = 1;
	// 	term.c_cc[VTIME] = 0;
	// 	term.c_lflag &= ~(ICANON);
	// 	term.c_lflag &= ~(ECHO);
		if ((tcsetattr(0, TCSADRAIN, &term)) == -1)
			ft_putendl_fd("yo", 2);
	//}
		clear_term_get_size(&info, list);
		open(0, O_RDONLY);
	}
}

static void	my_sigtstp(int signum)
{
	char fake_sig[2];

	if (signum == SIGTSTP)
	{
		(void)signum;
		fake_sig[0] = config.c_cc[VSUSP];
		fake_sig[1] = '\0';
		
		if (ioctl(0, TIOCSTI, fake_sig) == -1)
			ft_putendl("fail ioclt");
		else
			signal(SIGTSTP, SIG_DFL);
		close(0);
		return_to_term(&config);
	}
}

//|| signum == SIGINT || signum == SIGQUIT

void	ft_signal(void)
{
	signal(SIGWINCH, &my_sigwinch);
	signal(SIGTSTP, &my_sigtstp);
	signal(SIGCONT, &my_sigwinch);
	//signal(SIGINT, &my_sigtstp);
	//signal(SIGQUIT, &my_sigtstp);
}