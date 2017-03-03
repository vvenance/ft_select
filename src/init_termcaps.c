#include "../inc/ft_select.h"

int	init_termcaps(struct termios *term, struct termios *config)
{
	char			*tname;

	if (!(tname = ttyname(0)))
		return (0);
	if ((tname = getenv("TERM")) != NULL && tgetent(NULL, tname) == 1
		&& tcgetattr(0, config) != ERR)
	{
		term = config;
		term->c_cc[VMIN] = 1;
		term->c_cc[VTIME] = 0;
		term->c_lflag &= ~(ICANON);
		term->c_lflag &= ~(ECHO);
		if ((tcsetattr(0, TCSADRAIN, term)) != -1)
			return (1); 
	}
	return (0);
}
