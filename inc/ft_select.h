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

typedef struct	s_entry
{
	char		*name;
	int			selected;
	s_entry		*prev;
	s_entry		*next;
}				t_entry;

#endif