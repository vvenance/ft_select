#ifndef FT_SELECT_H
#define FT_SELECT_H
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <signal.h>
#include "../libft/inc/libft.h"

typedef struct	s_dclist
{
	char		*name;
	s_dclist	*prev;
	s_dclist	*next;
}				t_dclist;

typedef struct	s_info
{
	int			nb_elem;
	int			name_maxlen;
}				t_info;

#endif