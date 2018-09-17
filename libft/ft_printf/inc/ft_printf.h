/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oskulska <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:19:56 by oskulska          #+#    #+#             */
/*   Updated: 2018/03/13 19:20:46 by oskulska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>

# define FLAGS "#-+0 hljz"
# define DIGITS "0123456789."
# define CONV "idDoOuUxXsScCp%"

typedef struct		s_format
{
	int				flag_zero;
	int				flag_hash;
	int				flag_minus;
	int				flag_plus;
	int				flag_space;
	int				width;
	int				precision;
	int				length_h;
	int				length_l;
	int				length_j;
	int				length_z;
	char			type;
}					t_format;

t_format			*ft_creatstrctr(void);
int					ft_printf(const char *format, ...);
int					ft_notion(va_list *argptr, char **str, int *ret);
int					ft_not2(va_list *argptr, char **str, int *ret, t_format *p);
void				ft_check_flags(t_format *p, char sym);
void				ft_define_wp(t_format *p, char *str, int *pos);
int					ft_define_conversion\
					(va_list *argptr, t_format *p, char str);
int					ft_parse_conversions(t_format *p, va_list *argptr);
intmax_t			ft_parse_signed_length(t_format *p, va_list *argptr);
uintmax_t			ft_parse_unsigned_length(t_format *p, va_list *argptr);
void				ft_parse_width(t_format *p, int len_arg);
void				ft_parse_precision(t_format *p, int len_arg, int *ret);
int					ft_manage_signed_numbers(va_list *argptr, t_format *p);
int					ft_manage_unsigned_numbers(va_list *argptr, t_format *p);
wint_t				ft_parse_chars_length(t_format *p, va_list *argptr);
int					ft_manage_chars(va_list *argptr, t_format *p);
int					ft_manage_strings(va_list *argptr, t_format *p);
int					ft_manage_pointers(va_list *argptr, t_format *p);
int					ft_manage_nonvalid(t_format *p, char str);
void				ft_print_space_zero(t_format *p, int *ret);
void				wstr_byte(wchar_t *str, t_format *p);
int					ft_putwchar(wchar_t smb);
int					ft_putwstr(wchar_t *s);

#endif
