#include "ft_printf.h"
#include "libft.h"

int				ft_print_petcent(t_printf_arg *args)
{
	int length;

	length = 1;	
	args->length = length;
	if (!(args->flag_minus))
		length += ((args->width == 0) ? 0 : ft_deal_width(args));
	ft_putchar('%');
	if (args->flag_minus)
		length += ((args->width == 0) ? 0 : ft_deal_width(args));	
	// printf("Returned length: %d\n", length);	
	return (length);
}

// int				ft_dispatcher(t_printf_arg *args, va_list list)
// {
// 	int i;

// 	// return (0);
// 	i = 0;
// 	if (args->type == 'd')
// 		i = ft_printf_decimal(args, list);
// 	else if (args->type == 'u')
// 		i = ft_printf_udecimal(args, list);
// 	else if (args->type == 'x' || args->type == 'X' || args->type == 'p')
// 		i = ft_printf_hexa(args, list);
// 	else if (args->type == 'o')
// 		i = ft_printf_octal(args, list);
// 	else if (args->type == 'c')
// 		i = ft_printf_char(args, list);
// 	else if (args->type == 's')
// 		i = ft_printf_str(args, list);
// 	else if (args->type == 'f')
// 		ft_printf_float(args ,va_arg(list, double));
// 	else if (args->type == '%')
// 		i = ft_print_petcent(args);
// 	return (i);
// }
int				ft_dispatcher(t_printf_arg *args, va_list list)
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
		if (args->flag_minus == 0)
			i += ((args->width == 0) ? 0 : (ft_deal_width(args)));
		ft_putchar(args->notype);
		if (args->flag_minus)
			i += ((args->width == 0) ? 0 : (ft_deal_width(args)));
		i += args->length;
	}
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
	int length;
	va_list list;
	t_printf_arg *args;

	i = 0;
	length = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (!(args = new_printf_args()))
				return (-1);
			i += get_flags(args, (format + i));
			// printf("i: %d\n", i);
			// ft_print_all_flags(args);
			length += ft_dispatcher(args, list);
			// printf("Returned length: %d\n", length);
			// printf("Format left: %s\n", format + i);
			// printf("Char: %c\n", format[i]);
			// ft_print_all_flags(args);
			free(args);
		}
		else
		{		
			ft_putchar(format[i]);
			length++;
			i++;
		}
			// printf("Returned length: %d\n", length);
		
		// i += ((format[i] == '%' && format[i + 1] == '%') ? 1 : 0);
	}
	va_end(list);
	return (length);
}
