#include "ft_printf.h"
#include "libft.h"

int	ft_deal_zero(t_printf_arg *args)
{
	int toprint;
	int printed;

	toprint = args->width - (args->flag_space || args->flag_plus) - args->length;
	printed = toprint;
	while (toprint)
	{
		ft_putchar('0');
		toprint--;
	}
	return (printed);
}

int ft_get_length(intmax_t nb, int base)
{
	int length;

	if (!nb)
		return (1);
	length = 0;
	while (nb)
	{
		nb /= base;
		length++;
	}
	return (length);
}


int ft_get_un_length(uintmax_t nb, int base)
{
	int length;

	if (!nb)
		return (1);
	length = 0;
	while (nb)
	{
		nb /= base;
		length++;
	}
	return (length);
}

int	ft_deal_plus_space(t_printf_arg *args)
{
	if (!args->neg)
	{
		if (args->flag_plus)
			ft_putchar('+');
		else if (args->flag_space)
			ft_putchar(' ');			
	}
	else
		ft_putchar('-');
	return (1);		
}

int	ft_deal_precision(t_printf_arg *args)
{
	int toprint;
	int printed;

	toprint = args->precision - args->length;
	printed = toprint;
	while (toprint > 0)
	{
		ft_putchar('0');
		toprint--;
	}
	return (printed);
}

int	ft_deal_width(t_printf_arg *args)
{
	int	toprint;
	int	printed;

	toprint = args->width - args->precision - (args->flag_space || args->flag_plus) - args->length;
	// printf("Printed: %d, Width: %d, Precision: %d, Length: %d\n", toprint,  args->width, args->precision, args->length);
	if ((args->type != 's' && args->type != 'f') && args->precision)
		toprint += ((args->precision > args->length) ? args->length : args->precision);
	else if (args->type == 's' && args->precision)
		toprint += ((args->precision > args->length) ? 0 : args->length);
	printed = toprint;
	while (toprint > 0)
	{
		if (args->flag_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		toprint--;
	}
	return (printed);
}

int	ft_deal_number(t_printf_arg *args, intmax_t nb)
{
	int i;

	i = 0;
	args->length = ft_get_length(nb, 10);
	args->neg = (nb < 0 ? 1 : 0);
	if (args->flag_minus == 0 && !(args->type == 'd' && args->flag_zero == 1))
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
	if (args->flag_space || args->flag_plus || args->neg)
		i += ft_deal_plus_space(args);
	if (args->flag_zero)
		i += ft_deal_zero(args);
	if (args->precision)
		i += ft_deal_precision(args);
	if ((args->conv_s == 'l' && args->type == 'u') || args->type == 'U')
		i += ft_putlunbr((unsigned long)nb);
	else if ((args->conv_s == 'l' && args->type == 'o') || args->type == 'O')
		i += ft_putlunbr((unsigned long)nb);	
	else if (args->conv_s == 'l' || args->type == 'u' || args->type == 'o')
		i += ft_putlunbr(nb);
	else
		i += ft_putunbr(nb);
	if (args->flag_minus)
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
	return (i);
}

int	ft_deal_number_str(t_printf_arg *args, uintmax_t nb, int base)
{
	int		i;
	char	*str_nb;

	if (args->type == 'x' || args->type == 'X')
		str_nb = ft_convert_base_hexa(nb, args->type);
	else
		str_nb = ft_convert_base_str(nb, base);
	args->length = ft_get_length(nb, base);
	i = args->length;
	// args->neg = (nb < 0 ? 1 : 0);
	if (args->flag_minus == 0)
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
	if (args->flag_space || args->flag_plus || args->neg)
		i += ft_deal_plus_space(args);
	if (args->flag_zero)
		i += ft_deal_zero(args);
	if (args->precision)
		i += ft_deal_precision(args);
	ft_putstr(str_nb);
	if (args->flag_minus)
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
	return (i);
}

int	ft_printf_decimal(t_printf_arg *args, va_list list)
{
	int i;

	if (args->conv_s == 'j' || args->conv_s == 'z')
		i = ft_deal_number(args, va_arg(list, intmax_t));
	else if (args->conv_s == 'l' && args->conv_d == 'l')
		i = ft_deal_number(args, va_arg(list, long long));
	else if (args->conv_s == 'l')
		i = ft_deal_number(args, va_arg(list, long));
	else if (args->conv_s == 'h' && args->conv_d == 'h')
		i = ft_deal_number(args, (char)va_arg(list, int));
	else if (args->conv_s == 'h')
		i = ft_deal_number(args, (short)va_arg(list, int));
	else
		i = ft_deal_number(args, va_arg(list, int));
	return (i);
}

int	ft_printf_udecimal(t_printf_arg *args, va_list list)
{
	int i;
	
	i = 0;
	if (args->conv_s == 'j')
		i += ft_deal_number_str(args, va_arg(list, uintmax_t), 10);
	else if (args->conv_s == 'z')
		i += ft_deal_number_str(args, va_arg(list, size_t), 10);
	else if (args->conv_s == 'l' && args->conv_d == 'l')
		i += ft_deal_number_str(args, va_arg(list, unsigned long long), 10);
	else if (args->conv_s == 'l')
		i += ft_deal_number_str(args, va_arg(list, unsigned long), 10);
	else if (args->conv_s == 'h' && args->conv_d == 'h')
		i += ft_deal_number_str(args, (unsigned char)va_arg(list, unsigned int), 10);
	else if (args->conv_s == 'h')
		i += ft_deal_number_str(args, (unsigned short)va_arg(list, unsigned int), 10);
	else
		i += ft_deal_number_str(args, va_arg(list, unsigned int), 10);
	return (i);
}
