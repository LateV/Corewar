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

# define BUFF_SIZE 40

typedef struct		s_fd
{
	int				fd;
	char			*remainder;
}					t_fd;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_gnl_struct
{
	char				*content;
	char				*posle;
	int					fd;
	int					pos;
	char				**ret;
	struct s_gnl_struct	*next;
}				t_gnl_struct;

typedef struct	s_printf
{
	int			invalid;
	int			*zero;
	int			width;
	int			widthdef;
	int			precision;
	int			precisiondef;
	int			sign;
	char		flag[5];
	char		length[2];
	char		type[1];
	char		*buf;
	size_t		num;
}				t_printf;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_dig_count(int a);
int				ft_arr_len(char **arr);
int				ft_put_wchar(wchar_t c);
int				ft_atoi(const char *str);
int				ft_printf(char *str, ...);
int				ft_wchar_len(const wchar_t c);
int				ft_wandc_len(const wchar_t *s);
int				ft_count_words(char const *s, char c);
int				get_next_line(const int fd, char **line);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_format_type(int i, char *str, t_printf **format);
int				ft_intflagmins(t_printf **format, int out, int num);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_intnoflagmins(t_printf **format, int out, int num);
int				ft_intflagminsneg(t_printf **format, int out, int num);
int				ft_intnoflagminsneg(t_printf **format, int out, int num);
int				ft_specif(t_printf **format, char *str, int i, va_list argum);

void			ft_putnbr(int n);
void			ft_strclr(char *s);
void			ft_putchar(char c);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_arr_free(char **arr);
void			ft_putstr(char const *s);
void			ft_strtoupper(char *str);
void			ft_putendl(char const *s);
void			ft_freesh(t_printf *format);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_pputproc(t_printf **format);
void			ft_put_wcharstr(const wchar_t *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_reverse_bits(void *a, size_t size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_striter(char *s, void (*f)(char *));
void			ft_pputcharik(t_printf **format, char c);
void			ft_outp(t_printf *format, va_list argum);
void			ft_ppupad(t_printf **format, char *outc);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_pputstrik(t_printf **format, char *str);
void			ft_putxnolen(t_printf **format, char *outc);
void			ft_putdnolen(t_printf **format, char *outc);
void			ft_putonolen(t_printf **format, char *outc);
void			ft_pputstr(t_printf **format, va_list argum);
void			ft_pputchar(t_printf **format, va_list argum);
void			ft_pputdnbr(t_printf **format, va_list argum);
void			ft_pputunbr(t_printf **format, va_list argum);
void			ft_pputonbr(t_printf **format, va_list argum);
void			ft_pputxnbr(t_printf **format, va_list argum);
void			ft_intxposmin_1(t_printf **format, char *outc);
void			ft_intdposmin_1(t_printf **format, char *outc);
void			ft_intdnegmin_1(t_printf **format, char *outc);
void			ft_intoposmin_1(t_printf **format, char *outc);
void			ft_intonegmin_1(t_printf **format, char *outc);
void			ft_pput_wchar(t_printf **format, va_list argum);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_intoposnomin_1(t_printf **format, char *outc);
void			ft_intdposnomin_1(t_printf **format, char *outc);
void			ft_intdnegnomin_1(t_printf **format, char *outc);
void			ft_intonegnomin_1(t_printf **format, char *outc);
void			ft_intoposnomin_1(t_printf **format, char *outc);
void			ft_intxposnomin_1(t_printf **format, char *outc);
void			ft_pput_wchar_str(t_printf **format, va_list argum);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

char			*ft_itoa(int n);
char			*ft_pitoa(intmax_t n);
char			*ft_strnew(size_t size);
char			*ft_genchar(char c, int n);
char			*ft_strdup(const char *s1);
char			*ft_strtrim(char const *s);
char			*ft_genchar_s(char c, int n);
char			*ft_genchar_x(t_printf **format);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcat(char *s1, const char *s2);
char			**ft_strsplit(char const *s, char c);
char			*ft_strjoin_free_12(char *s1, char *s2);
char			*ft_strjoin_free_10(char *s1, char *s2);
char			*ft_strjoin_free_02(char *s1, char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_length_h(t_printf **format, va_list argum);
char			*ft_length_l(t_printf **format, va_list argum);
char			*ft_length_j(t_printf **format, va_list argum);
char			*ft_length_z(t_printf **format, va_list argum);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_itoa_base(unsigned long long num, int base);
char			*ft_lengthu_hh(t_printf **format, va_list argum);
char			*ft_length_ll(t_printf **format, va_list argum);
char			*ft_length_hh(t_printf **format, va_list argum);
char			*ft_lengthu_h(t_printf **format, va_list argum);
char			*ft_lengthu_l(t_printf **format, va_list argum);
char			*ft_lengthu_j(t_printf **format, va_list argum);
char			*ft_lengthu_z(t_printf **format, va_list argum);
char			*ft_lengthu_ll(t_printf **format, va_list argum);
char			*ft_llutoa_base(unsigned long long num, int base);
char			*ft_ppupadnomin_11(t_printf **format, char *outc);
char			*ft_length_nolen(t_printf **format, va_list argum);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_lengthu_nolen(t_printf **format, va_list argum);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_lengtho_h(t_printf **format, va_list argum, int base);
char			*ft_lengtho_l(t_printf **format, va_list argum, int base);
char			*ft_lengtho_j(t_printf **format, va_list argum, int base);
char			*ft_lengtho_z(t_printf **format, va_list argum, int base);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_lengtho_ll(t_printf **format, va_list argum, int base);
char			*ft_lengtho_hh(t_printf **format, va_list argum, int base);
char			*ft_lengtho_nolen(t_printf **format, va_list argum, int base);

void			*ft_memalloc(size_t size);
void			*ft_bzero(void *b, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

size_t			ft_strlen(const char *str);
size_t			ft_strlcat(char *dst, const char *src, size_t size);

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

int				ft_format_flag(int i, char *std_flag,
	char *str, t_printf **format);
int				ft_format_length(int i, char *stdl,
	char *str, t_printf **format);
int				ft_format_precision(int i, t_printf **format,
	char *str, va_list argum);
int				ft_format_length_1(int i, char *stdl,
	char *str, t_printf **format);
int				ft_format_width(int i, char *str,
	t_printf **format, va_list argum);
char			*ft_strnstr(const char *haystack,
const char *needle, size_t len);
#endif
