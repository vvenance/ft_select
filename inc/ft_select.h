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
#include <termcap.h>
#include "../libft/inc/libft.h"

typedef struct	s_dclist
{
	char		*name;
	int			length;
	struct s_dclist	*prev;
	struct s_dclist	*next;
}				t_dclist;

typedef struct	s_info
{
	int			nb_elem;
	int			name_maxlen;
	int			tcol;
	int			tline;
}				t_info;

void	add_elem_dcl(t_dclist **list, char *name);
int		init_termcaps(struct termios *term, struct termios *config);
void	del_elem_dcl(t_dclist **list, t_dclist *elem);
void	get_list(char **av, t_dclist **list, t_info *info);
void	return_to_term(struct termios *config);

#endif