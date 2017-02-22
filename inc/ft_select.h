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

# define CLASSIC 0
# define REVV 1
# define UNDERL 2
# define BOTH 3
# define POSX 0
# define POSY 1
# define SELECT 2
# define CURR 3
# define NAMLEN 4

typedef struct	s_dclist
{
	char		**name;
	int			know[5];
	struct s_dclist	*prev;
	struct s_dclist	*next;
}				t_dclist;

typedef struct	s_info
{
	int			nb_elem;
	int			name_maxlen;
	int			tcol;
	int			tline;
	int			elem_per_col;
	int			nb_lines;
}				t_info;

void	add_elem_dcl(t_dclist **list, char *name);
int		init_termcaps(struct termios *term, struct termios *config);
void	del_elem_dcl(t_dclist **list, t_dclist *elem);
void	get_list(char **av, t_dclist **list, t_info *info);
void	return_to_term(struct termios *config);
void	add_elem_dcl(t_dclist **list, char *str);
int		my_putc(int c);

#endif