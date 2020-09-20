/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmygeeto <cmygeeto@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:48:52 by cmygeeto          #+#    #+#             */
/*   Updated: 2020/07/28 23:41:40 by cmygeeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	connected_list
{
	void			*content;
	struct connected_list	*next;
}				list;

list			*ft_lstnew(void *content);
void			ft_lstadd_front(list **lst, list *new);
int				ft_lstsize(list *lst);
list			*ft_lstlast(list *lst);
void			ft_lstadd_back(list **lst, list *new);
void			ft_lstdelone(list *lst, void (*del)(void *));
void			ft_lstclear(list **lst, void (*del)(void *));
void			ft_lstiter(list *lst, void (*f)(void *));
list			*ft_lstmap(list *lst, void *(*f)(void *),
													void (*del)(void *));

typedef struct		s_list
{
	int				wd;
	int				zero;
	int				min;
	int				prc;
	int				prc_num;
	int				type;
	int				sign;
}					t_list;

void			ft_putchar(char c);
void			ft_putstr(const char *str);
int				ft_atoi(const char *str);
int				ft_isblank(int c);
int				ft_isspace(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_bzero(void *str, size_t n);
void			*ft_memccpy(void *destination, const void *source,
													int c, size_t n);
void			*ft_memchr(const void *arr, int c, size_t n);
int				ft_memcmp(const void *arr1, const void *arr2, size_t n);
void			*ft_memcpy(void *destination, const void *source, size_t n);
void			*ft_memmove(void *destination, const void *source, size_t len);
void			*ft_memset(void *destination, int c, size_t n);
int				ft_strlcpy(char *dest, const char *source, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *destination, const char *source, size_t size);
char			*ft_strchr(const char *source, int c);
char			*ft_strrchr(const char *source, int c);
char			*ft_strnstr(const char *str, const char *find, size_t len);
void			*ft_calloc(size_t num, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
void			ft_strdel(char **pos);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_printf(const char *line, ...);
t_list			*ft_save_flags(char *line, int i, t_list *save);
t_list			*ft_save_wd(char *line, int i, t_list *save, va_list args);
t_list			*ft_save_prc(char *line, int i, t_list *save, va_list args);
int				ft_print_c(t_list *save, va_list args);
int				ft_print_s(t_list *save, va_list args);
int				ft_print_per(t_list *save);
int				ft_print_p(t_list *save, va_list args);
int				ft_print_di(t_list *save, va_list args);
int				ft_print_u(t_list *save, va_list args);
int				ft_print_x(t_list *save, va_list args);
int				ft_treat_wd(char *line, int len, t_list *save);
char			*ft_treat_prc(char *line, t_list *save);
char			*ft_utoa(unsigned int u);
int				ft_is_type(char c);
t_list			ft_init_save(void);
int				ft_putcharl(char c);
int				ft_putstrl(char *s);
int				get_next_line(int fd, char **line);

#endif
