/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilk <mwilk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:27:02 by mwilk             #+#    #+#             */
/*   Updated: 2016/06/12 17:01:50 by mwilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define MIN(x, y)	(x < y) ? x : y
# define MAX(x, y)	(x > y) ? x : y
# define BUFF_SIZE 16

# define RED		"\033[31m"
# define GRN		"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define MAG		"\033[35m"
# define CYAN	"\033[36m"
# define RESET	"\033[0m"

/*
** TT_FUNCTIONS
*/

int				tt_ens(int nb, char *s, int ret);
int				tt_es(char *s, int ret);
int				tt_esn(char *s, int nb, int ret);
int				tt_ess(char *s, char *s2, int ret);
int				tt_gnl(int fd, char **line);
int				tt_pc(char c);
int				tt_pl(char *s);
int				tt_pn(int c);
int				tt_pns(int c, char *s);
int				tt_pnl(int c, char *s);
int				tt_ps(char *s);
int				tt_pss(char *s, char *s2);
int				tt_psl(char *s, char *s2);
int				tt_psn(char *s, int nb);
int				tt_psns(char *s, int nb, char *s2);
int				tt_pssn(char *s, char *s2, int nb);
int				tt_psss(char *s, char *s2, char *s3);
size_t			tt_slen(char *s);

unsigned char	*tt_ctob(int c);
void			tt_deltab(char **t, int size);
void			tt_half_increment(int *x, int *y);
char			**tt_malloc_tab(int size_1, int size_2);
int				**tt_malloc_intab(int size_1, int size_2);
void			tt_printab(char **t);
void			tt_printabtab(char ***t);
void			tt_printintab(int **t, int sizej, int sizei);
float			tt_sqrt(int x);
int				tt_swpnb(int *a, int *b);

/*
** TREE
*/

typedef struct	s_tree
{
	void			*content;
	size_t			content_size;
	struct s_tree	*right;
	struct s_tree	*left;
}				t_tree;

t_tree			*tt_tree_add
					(t_tree *root, t_tree *node, int (*cmp)(void *, void *));
void			tt_tree_del(t_tree **parent, void (*del)(void *, size_t));
int				tt_tree_h(t_tree *node);
t_tree			*tt_tree_new(void *content, size_t content_size);
void			tt_tree_iter_ord(t_tree *head, void (*f)(t_tree *node));
void			tt_tree_iter_rev(t_tree *head, void (*f)(t_tree *node));

/*
** LISTS
*/
typedef struct	s_gnl
{
	char			*line;
	int				fd;
	struct s_list	*next;
}				t_gnl;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddq(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstlast(t_list *alst);
void			ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void *content, size_t content_size);

/*
** LISTS
*/

int				tt_intlen(int nb);

/*
** CONVERT
*/

int				ft_atoi(const char *str);
int				ft_abs(int c);
char			*ft_itoa(int c);
unsigned char	*ft_ctob(int c);

/*
** DIVERS  O.O
*/
void			ft_bzero(void *str, size_t n);
void			*ft_realloc(void *ptr, size_t old, size_t size);

/*
** FT_IS
*/
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isblank(int c);
int				ft_isdigit(int c);
int				ft_isgraph(int c);
int				ft_islower(int c);
int				ft_isnumber(char *s);
int				ft_isprint(int c);
int				ft_isupper(int c);
int				ft_isspace(int c);

/*
** FT_MEM
*/
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, void *src, int c, size_t n);
void			*ft_memchr(void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, void *src, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);

/*
** FT_PUT
*/
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(char *s, int fd);

/*
** FT_STR
*/
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchartrim(const char *s, char c);
char			*ft_strchr(char *str, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(const char *s1, const char *s2);
char			*ft_strgroupchar(const char *s, char c);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
char			**ft_strsplit(const char *s, char c);
char			*ft_strstr(char *s1, char *s2);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
size_t			ft_strlcat(char *dst, char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strncat(char *dst, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, char *src, size_t n);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strnjoin(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(char *s1, char *s2, size_t n);
char			*ft_strrchr(char *str, int c);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s);

/*
** FT_TO
*/

int				ft_tolower(int c);
int				ft_toupper(int c);

/*
** GNL
*/

int				get_next_line(const int fd, char **line);
#endif
