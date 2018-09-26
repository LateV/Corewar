/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vibondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:51:51 by vibondar          #+#    #+#             */
/*   Updated: 2017/10/30 12:52:00 by vibondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stddef.h>
# include <locale.h>

# define BUFF_SIZE 200

typedef struct	s_fd
{
	int					fd;
	char				*remainder;
}				t_fd;

typedef struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;

typedef struct	s_gnl_struct
{
	char					*content;
	char					*posle;
	int						fd;
	int						pos;
	char					**ret;
	struct s_gnl_struct		*next;
}				t_gnl_struct;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_bytelen(wchar_t c);
int				ft_dig_count(int a);
int				ft_arr_len(char **arr);
int				ft_put_wchar(wchar_t c);
int				ft_atoi(const char *str);
int				ft_wchar_len(const wchar_t c);
int				ft_wandc_len(const wchar_t *s);
int				ft_count_words(char const *s, char c);
int				get_next_line(const int fd, char **line);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_putnbr(int n);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_arr_free(char **arr);
void			ft_uppercase(char **str);
void			ft_putstr(char const *s);
void			ft_strtoupper(char *str);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_put_wcharstr(const wchar_t *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_reverse_bits(void *a, size_t size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_striter(char *s, void (*f)(char *));
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

char			ft_loweret(char a);

char			*ft_itoa(int n);
char			*ft_pitoa(intmax_t n);
char			*ft_strnew(size_t size);
char			*ft_genchar(char c, int n);
char			*ft_strdup(const char *s1);
char			*ft_strtrim(char const *s);
char			*ft_genchar_s(char c, int n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strndup(const char *s1, int n);
char			*ft_strcat(char *s1, const char *s2);
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoin_free_12(char *s1, char *s2);
char			*ft_strjoin_free_10(char *s1, char *s2);
char			*ft_strjoin_free_02(char *s1, char *s2);
char			*ft_itoa_ubase(uintmax_t number, int base);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_itoa_base(unsigned long long num, int base);
char			*ft_llutoa_base(unsigned long long num, int base);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			*ft_memalloc(size_t size);
void			*ft_bzero(void *b, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

size_t			ft_strlen(const char *str);
size_t			ft_len_num(intmax_t n);
size_t			ft_wstrlen(wchar_t *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

char			*ft_strnstr(const char *haystack,
	const char *needle, size_t len);
#endif
