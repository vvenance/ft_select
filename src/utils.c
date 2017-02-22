#include "../inc/ft_select.h"

void return_to_term(struct termios *config)
{
	char *str;
	
	str = tgetstr("cnorm", NULL);
	tputs(str, 0, &my_putc);
	if (tcgetattr(0, config) != -1)
		exit(1);
}