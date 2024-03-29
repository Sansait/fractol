/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:00:29 by sklepper          #+#    #+#             */
/*   Updated: 2018/05/23 17:09:43 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_puttab(char **tab);
void			ft_putnbr(int n);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memmove(void *dest, const void *src, size_t n);
char			*ft_strnew(size_t size);
void			ft_memdel(void **ap);
size_t			ft_strlen(const char *str);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
int				ft_power(int n, int p);
void			ft_putendl(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
char			*ft_strncat(char *dest, const char *src, int nb);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strrchr(const char *s, int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
char			*ft_strncpy(char *dest, const char *src, size_t n);
size_t			ft_min(size_t a, size_t b);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isalnum(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strncmp(char *s1, char *s2, size_t n);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstaddend(t_list **alst, t_list *new);
size_t			ft_max(size_t a, size_t b);
int				ft_lstsize(t_list *begin_list);
t_list			*ft_lstlast(t_list *begin_list);
t_list			*ft_lstat(t_list *begin_list, unsigned int nbr);
void			ft_lstrev(t_list **begin_list);
char			*ft_strjoinch(char *s1, char c);
char			*ft_straddend(char *s1, char const *s2);
char			*ft_strremb(char *str, char c);
int				ft_copyuntil(char **dst, char *src, char c);
int				get_next_line(int fd, char **line);
int				ft_count_words(char const *str, char c);
int				ft_is_space(int c);

#endif
