#include "ft_printf.h"

int				ft_dispatcher(t_printf_arg *args, va_list list)
{
	int i;

	i = 0;
	if (args->type == 'd' || args->type == 'u')
		i = ft_printf_decimal(args, list);
	else if (args->type == 'u')
		i = ft_printf_udecimal(args, list);		
	else if (args->type == 'x' || args->type == 'p')
		i = ft_printf_hexa(args, list);
	else if (args->type == 'o')
		i = ft_printf_octal(args, list);		
	else if (args->type == 'c')
		i = ft_printf_char(args, list);
	else if (args->type == 's')
		ft_printf_str(args, list);
	else if (args->type == 'f')
		ft_printf_float(args ,va_arg(list, double));
	return (i);
}

t_printf_arg	*new_printf_args(void)
{
	t_printf_arg *args;

	if (!(args = (t_printf_arg*)malloc(sizeof(t_printf_arg))))
		return (NULL);
	args->flag_minus = 0;
	args->flag_plus = 0;
	args->flag_space = 0;
	args->flag_hash = 0;
	args->flag_zero = 0;
	args->precision = 0;
	args->set_precision = 0;
	args->length = 0;
	args->neg = 0;
	args->width = 0;
	return (args);
}

int ft_printf(const char *format, ...)
{
	int i;
	int length;
	va_list list;
	t_printf_arg *args;

	i = -1;
	va_start(list, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[++i] != '%' && format[i] != '\0')
		{
			if (!(args = new_printf_args()))
				return (-1);
			i = i + get_flags(args, (format + i));
			length = ft_dispatcher(args, list);
		}
		ft_putchar(format[i]);
	}
	va_end(list);
	return (length);
}
