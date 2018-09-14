#include "ft_printf.h"
#include "libft.h"

int				ft_print_petcent(t_printf_arg *args)
{
	int length;

	length = 1;	
	args->length = length;
	if (!(args->fl_minus))
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	ft_putchar('%');
	if (args->fl_minus)
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	return (length);
}

// int				ft_dispatcher(t_printf_arg *args, va_list list)
// {
// 		ft_printf_float(args ,va_arg(list, double));
// }
int				ft_dispatcher(t_printf_arg *args, va_list list, int ret)
{
	int i;

	i = 0;
	if (args->type == 'd')
		i = ft_printf_decimal(args, list);
	else if (args->type == 'u')
		i = ft_printf_udecimal(args, list);
	else if (args->type == 'x' || args->type == 'X' || args->type == 'p')
		i = ft_printf_hexa(args, list);
	else if (args->type == 'o')
		i = ft_printf_octal(args, list);
	else if (args->type == 'b')
		i = ft_deal_nbr_str(args, va_arg(list, uintmax_t), 2);
	else if (args->type == 'q')
		i = ft_printf_conv_binary(args, va_arg(list, char *));
	else if (args->type == 'c')
		i = ft_printf_char(args, list);
	else if (args->type == 's')
		i = ft_printf_str(args, list);
	else if (args->type == 'f')
		return (0);
	else if (args->type == '%')
		i = ft_print_petcent(args);
	else if (args->type == 'Z')
	{
		args->length = 1;
		if (args->fl_minus == 0)
			i += ((args->width <= 0) ? 0 : (ft_deal_width(args)));
		if (args->notype != 0)
			ft_putchar(args->notype);
		if (args->fl_minus)
			i += ((args->width <= 0) ? 0 : (ft_deal_width(args)));
		i += args->length;
	}
	if (i == -1)
		return (i);
	return (ret + i);
}

t_printf_arg	*new_printf_args(void)
{
	t_printf_arg *args;

	if (!(args = (t_printf_arg*)malloc(sizeof(t_printf_arg))))
		return (NULL);
	args->fl_minus = 0;
	args->fl_plus = 0;
	args->fl_space = 0;
	args->fl_hash = 0;
	args->fl_zero = 0;
	args->precision = 0;
	args->set_precision = 0;
	args->neg = 0;
	args->length = 0;
	args->type = 0;
	args->type = 0;
	args->conv_s = 0;
	args->conv_d = 0;
	args->width = 0;
	return (args);
}


int				ft_printf(const char *format, ...)
{
	int i;
	int ret;
	va_list list;
	t_printf_arg *args;

	i = 0;
	ret = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (!(args = new_printf_args()))
				return (-1);
			i += get_flags(args, (format + i), list);
			if ((ret = ft_dispatcher(args, list, ret)) == -1)
			{
			// free(args);

				return (-1);
			}
			free(args);
		}
		else
		{		
			ft_putchar(format[i]);
			ret++;
			i++;
		}
	}
	va_end(list);
	return (ret);
}
