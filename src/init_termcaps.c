#include "../inc/ft_select.h"

int	init_termcaps(struct termios *term, struct termios *config)
{
	char			*tname;

	if (!(tname = ttyname(0)))
		return (0);
	if ((tname = getenv("TERM")) != NULL && tgetent(NULL, tname) == 1
		&& tcgetattr(0, config) != ERR)
	{
		term->c_iflag = config->c_iflag;
		term->c_oflag = config->c_oflag;
		term->c_cflag = config->c_cflag;
		term->c_lflag = 0;
		term->c_cc[VMIN] = 1;
		term->c_cc[VTIME] = 0;
		term->c_lflag &= ~(ICANON);
		term->c_lflag &= ~(ECHO);
		if ((tcsetattr(0, TCSANOW, term)) != -1)
			return (1); 
	}
	return (0);
}

void return_to_term(struct termios *config)
{
	;
}