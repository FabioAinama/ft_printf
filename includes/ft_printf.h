#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_printf_arg
{
	int flag_hash;
	int flag_minus;
	int flag_plus;
	int flag_space;
	int flag_zero;
	int precision;
	int set_precision;
	int neg;
	int length;
	char type;
	char conv_s;
	char conv_d;
	unsigned int width;
}				t_printf_arg;

int			ft_printf(const char *format, ...);
int			get_flags(t_printf_arg *args, const char *format);
int			ft_printf_decimal(t_printf_arg *args, va_list list);
int			ft_printf_udecimal(t_printf_arg *args, va_list list);
int			ft_printf_octal(t_printf_arg *args, va_list list);
int			ft_printf_hexa(t_printf_arg *args, va_list list);
int			ft_printf_char(t_printf_arg *args, va_list list);
// void		ft_deal_number(t_printf_arg *args, intmax_t nb);
int			ft_deal_number_str(t_printf_arg *args, uintmax_t nb, int base);
void		ft_printf_float(t_printf_arg *args, double nb);
int			ft_printf_str(t_printf_arg *args, va_list list);
int			ft_deal_width(t_printf_arg *args);
int			ft_get_length(intmax_t nb, int base);

char		*ft_convert_octal(long int nb);
char		*ft_convert_base_hexa(uintmax_t nb, char base);
int			ft_putunbr(int n);
int			ft_putlunbr(uintmax_t n);
int			ft_get_un_length(uintmax_t nb, int base);
char		*ft_convert_base_str(uintmax_t nb, int base);

// Utils
int			ft_isupper(char c);
char		*ft_strrev(char *str);
int			ft_wcharlen(wchar_t wchar);
wchar_t		*ft_wstrdup(wchar_t *src);
size_t		ft_wstrlen(const wchar_t *wstr);
wchar_t		*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len);
wchar_t		*ft_wstrnew(size_t size);
int			ft_putwchar(wchar_t wchar);

// void		ft_print_all_flags(t_printf_arg *args);

#endif