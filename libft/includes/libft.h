/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:43:43 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/16 15:47:02 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <limits.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
int					ft_isascii(int c);
int					ft_isalnum(int c);
char				*ft_strchr(const char *s, int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle\
					, size_t len);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strdup(const char *s1);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *)\
					, void (*del)(void *));
void				ft_advanced_sort_string_tab(char **tab, int (*cmp)\
					(char *, char *));
int					ft_atoi_base(char *str, char *base);
int					ft_check_error(char *base);
int					ft_islower(int c);
int					ft_isupper(int c);
char				*ft_itoa_base(int nbr, char *base, char *buf);
void				ft_putnbr_base_fd(int nbr, char *base, int fd);
void				ft_rev_int_tab(int *tab, int size);
char				*ft_reverse_string(char *buf);
void				ft_sort_int_tab(int *tab, int size);
void				ft_sort_string_tab(char **tab);
void				ft_swap(int *a, int *b);
void				ft_swap_str(char **s1, char **s2);
int					ft_whitespace(char c);

int					get_next_line(int fd, char **line);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_supstr(char *s, unsigned int start, size_t len, int b);
int					ft_memchr_g(const void *s, int c, size_t n);
void				*ft_c(size_t count, size_t size);

typedef struct		s_flags
{
	int				zero;
	int				minus;
	int				width;
	int				prec;
	int				len;
	int				hexa;
	int				sign;
	char			to_print;
}					t_flags;

int					ft_printf(const char *format, ...)
					 __attribute__((format(printf,1,2)));

void				ft_parse_format(char *format, va_list ap, t_flags *arg,
					int *index);
void				ft_parse_flags(char *format, int *i, t_flags *arg);
void				ft_parse_width(char *format, va_list ap, int *i,
					t_flags *arg);
void				ft_parse_prec(char *format, va_list ap, int *i,
					t_flags *arg);

void				ft_print_char(va_list ap, int *ret, t_flags *arg);
void				ft_print_string(va_list ap, int *ret, t_flags *arg);
void				ft_print_adress(va_list ap, int *ret, t_flags *arg);
void				ft_print_int(va_list ap, int *ret, t_flags *arg);
void				ft_print_unsigned(va_list ap, int *ret, t_flags *arg);
void				ft_print_hexa(va_list ap, int *ret, t_flags *arg, char c);
void				ft_print_percent(int *ret, t_flags *arg);

int					ft_get_percent(char *format);
int					ft_puts(char *str);
int					ft_putc(char c, int nb);
int					ft_putnb_pos(long nb, t_flags *arg);
int					ft_count_int(long nb);
int					ft_put_hexa(unsigned int nb, t_flags *arg);
int					ft_count_hexa(unsigned int nb);
int					ft_put_hexa_ll(unsigned long long nb);
int					ft_count_hexa_ll(unsigned long long nb);
double				ft_power(double x, unsigned int pow);
double				ft_sqrt(double nb);

#endif
