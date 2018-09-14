#include "ft_printf.h"
#include "libft.h"

int	ft_printf_octal(t_printf_arg *args, va_list list)
{
	int i;

	if (args->conv_s == 'j')
		i = ft_deal_nbr_str(args, va_arg(list, uintmax_t), 8);
	else if (args->conv_s == 'z')
		i = ft_deal_nbr_str(args, va_arg(list, size_t), 8);
	else if (args->conv_s == 'l' && args->conv_d == 'l')
		i = ft_deal_nbr_str(args, va_arg(list, unsigned long long), 8);
	else if (args->conv_s == 'l')
		i = ft_deal_nbr_str(args, va_arg(list, unsigned long), 8);
	else if (args->conv_s == 'h' && args->conv_d == 'h')
		i = ft_deal_nbr_str(args, (unsigned char)va_arg(list, unsigned int), 8);
	else if (args->conv_s == 'h')
		i = ft_deal_nbr_str(args, (unsigned short)va_arg(list, unsigned int), 8);
	else
		i = ft_deal_nbr_str(args, va_arg(list, unsigned int), 8);
	return (i);
}
