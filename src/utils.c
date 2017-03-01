#include "../inc/ft_select.h"

void return_to_term(struct termios *config)
{
	char *str;
	
	config->c_lflag &= ~(ISIG);
	str = tgetstr("cnorm", NULL);
	tputs(str, 0, &my_putc);
	str = tgetstr("ve", NULL);
	tputs(str, 0, &my_putc);
	if (tcgetattr(0, config) != -1)
		exit(1);
}

int		my_putc(int c)
{
	write(isatty(1), &c, 1);
	return (0);
}