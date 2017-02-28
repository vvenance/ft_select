#include "../inc/ft_select.h"

extern t_dclist *list;
extern t_info	info;

static int 

void	ft_signal(void)
{
	signal(SIGWINCH, &my_sigwinch);
}