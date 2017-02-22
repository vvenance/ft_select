#include "../inc/ft_select.h"

void return_to_term(struct termios *config)
{
	if (tcgetattr(0, config) != -1)
		exit(1);
}