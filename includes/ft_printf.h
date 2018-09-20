#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>
# include <locale.h>

typedef struct	s_printf_arg
{
	int		fl_hash;
	int		fl_minus;
	int		fl_plus;
	int		fl_space;
	int		fl_zero;
	int		precision;
	int		set_precision;
	int		neg;
	int		length;
	char	type;
	char	notype;
	char	conv_s;
	char	conv_d;
	int		width;

}				t_printf_arg;


int			ft_printf(const char *format, ...);
int			get_flags(t_printf_arg *args, const char *format, va_list list);
int			get_alpha_flags(t_printf_arg *args, const char *format, int i);
int			ft_printf_decimal(t_printf_arg *args, va_list list);
int			ft_deal_number(t_printf_arg *args, intmax_t nb);
int			ft_printf_udecimal(t_printf_arg *args, va_list list);
int			ft_printf_octal(t_printf_arg *args, va_list list);
int 		ft_printf_conv_binary(t_printf_arg *args, char *binary);
int			ft_printf_hexa(t_printf_arg *args, va_list list);
int			ft_printf_char(t_printf_arg *args, va_list list);
int			ft_deal_nbr_str(t_printf_arg *args, uintmax_t nb, int base);
int			ft_printf_float(t_printf_arg *args, double nb);
int			ft_printf_str(t_printf_arg *args, va_list list);
int			ft_deal_width(t_printf_arg *args);
int			ft_get_length(intmax_t nb, int base);
int			ft_get_un_length(uintmax_t nb, int base);
int			ft_dispatcher(t_printf_arg *args, va_list list, int ret);
char		*ft_convert_octal(long int nb);
char		*ft_convert_base_hexa(uintmax_t nb, char base);
int			ft_putunbr(int n);
int			ft_putlunbr(uintmax_t n);
int			ft_putlnbr(intmax_t n);
int			ft_get_un_length(uintmax_t nb, int base);
char		*ft_convert_base_str(uintmax_t nb, int base);
int			ft_deal_zero(t_printf_arg *args);
int			ft_deal_plus_space(t_printf_arg *args);
int			ft_deal_precision(t_printf_arg *args);
int			ft_deal_hash(t_printf_arg *args, uintmax_t nb);
int			ft_deal_width(t_printf_arg *args);


#endif
