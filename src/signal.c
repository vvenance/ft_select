#include "../inc/ft_select.h"

extern t_dclist *list;
extern t_info info;
extern struct termios config;
extern struct termios term;

static void my_sigcont(void)
{
	int ret;

	if (getenv("TERM") == NULL)
		ft_putendl("getenv issue");
	else
	{ 
		ret = open("/dev/tty", O_RDONLY);
		ret = init_termcaps(&term, &config);
		clear_term_get_size(&info, list);
	}
}

static void my_sigtstp(void)
{
	char fake_sig[2];

	fake_sig[0] = config.c_cc[VSUSP];
	fake_sig[1] = '\0';

	if (ioctl(0, TIOCSTI, fake_sig) == -1)
		ft_putendl("ioctl fail");
	else
		signal(SIGTSTP, SIG_DFL);
	close(0);
	return_to_term(&config);
}

static void my_sighandler(int sig)
{
	if (sig == SIGWINCH)
		clear_term_get_size(&info, list);
	else if (sig == SIGTSTP)
		my_sigtstp();
	else if (sig == SIGCONT)
		my_sigcont();
	else
		signal(sig, SIG_IGN);
}

void ft_signal(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i, my_sighandler);
		i++;
	}
}