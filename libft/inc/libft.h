/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvenance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:11:39 by vvenance          #+#    #+#             */
/*   Updated: 2016/11/14 18:11:44 by vvenance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <wchar.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "get_next_line.h"
# define _MALLOCC (char *)malloc

typedef struct		s_file
{
	int				fd;
	char			*str;
}					t_file;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_node
{
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_dlist
{
	t_node			*first;
	t_node			*last;
	size_t			lenght;
}					t_dlist;

typedef struct		s_save
{
	char			*save;
	int				fd;
}					t_save;

char				*ft_strjoin_free(char const *s1, char const *s2);
t_dlist				*ft_dlst_push_back(t_dlist *list, t_node *new);
t_dlist				*ft_create_list(void);
t_node				*ft_create_node(void);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstgetn(t_list **lst, int n);
int					ft_lstaddend(t_list **alst, t_list *new);
void				ft_lst_push_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putwstr_fd(wchar_t *chr, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putaddr(void *addr);
void				ft_putdouble(double d);
void				ft_putldouble(long double d);
void				ft_putlint(long int n);
void				ft_putulint(unsigned long int n);
void				ft_swap(int *a, int *b);
void				ft_swap2(int *xdep, int *xfin, int *ydep, int *yfin);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
char				*ft_strcapitalize(char *str);
char				*ft_strlowcase(char *str);
char				*ft_strupcase(char *str);
char				*ft_strrev(char *str);
char				*ft_strnrev(char *c, const int len);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strtrim(char const *s);
char				*ft_strtrim2(char const *s);
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_wstrlen(wchar_t *chr);
size_t				ft_lstlen(t_list *lst);
int					ft_strcchr(char *str, char c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_withoutspacelen(const char *str);
int					ft_nbword(const char *s, const char c);
int					ft_atoi(const char *str);
long double			ft_power(long double x, long double y);
long double			ft_floorl(long double x);
int					ft_sqrt(int nb);
int					ft_recursive_factorial(int nb);
int					ft_recursive_power(int nb, int power);
int					ft_cat(int fd);
int					ft_str_is_alpha(char *str);
int					ft_str_is_numeric(char *str);
int					ft_str_is_printable(char *str);
int					ft_str_is_uppercase(char *str);
int					ft_str_is_lowercase(char *str);
int					ft_find_next_prime(int nb);
int					ft_is_negative(int nb);
int					ft_is_prime(int nb);
int					ft_isspace(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_free(int nb, ...);

#endif
