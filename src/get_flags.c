#include "ft_printf.h"
#include "libft.h"

int	get_conv_flags(t_printf_arg *args, const char *format, int i)
{
	char c;

	c = format[i];
	while (c == 'l' || c == 'h' || c == 'j' || c == 'z')
	{
		if (format[i] == 'l')
		{
			(!args->conv_d && args->conv_s == 'l') ? args->conv_d = 'l' : 0;
			(!args->conv_s) ? args->conv_s = 'l' : 0;
		}
		else if (format[i] == 'h')
		{
			(!args->conv_d && args->conv_s == 'h') ? args->conv_d = 'h' : 0;
			(!args->conv_s) ? args->conv_s = 'h' : 0;	
		}
		else if (format[i] == 'j' || format[i] == 'z')
			args->conv_s = format[i];
		c = format[++i];
	}
	return (i);
}

int get_minus_zero_flag(t_printf_arg *args, const char c)
{
	if (c == '-')
	{
		args->flag_minus = 1;
		args->flag_zero = 0;
	}
	if (c == '0' && !(args->flag_minus))
		args->flag_zero = 1;
	return (1);
}

int get_plus_space_flag_hash(t_printf_arg *args, const char c)
{
	if (c == '#')
		args->flag_hash = 1;
	if (c == '+')
	{
		args->flag_plus = 1;
		args->flag_space = 0;
	}
	if (c == ' ' && !(args->flag_plus))
		args->flag_space = 1;
	return (1);
}

int	get_wildcard(t_printf_arg *args, int *ptr, va_list list, int width)
{
	int nb;

	nb = va_arg(list, int);
	if (width)
	{
		if (nb < 0)
		{
			nb = -nb;
			args->flag_minus = 1;
		}
	}
	*ptr = nb;
	return (1);
}

int get_precision_flag(t_printf_arg *args, const char *format, va_list list)
{
	int i;

	i = 0;
	if (format[i] >= '0' && format[i] <= '9')
	{
		args->precision = ft_atoi(format);
		i = i + 1 + ft_get_length(args->precision, 10);
	}
	else if (format[i] == '*')
		i = i + 1 + get_wildcard(args, &(args->precision), list, 0);
	else
	{
		args->precision = 0;
		i++;
	}
	args->set_precision = 1;
	return (i);
}

int get_flags(t_printf_arg *args, const char *format, va_list list)
{
	int i;

	i = 0;
	while (!(args->type) && format[i])
	{
		if (format[i] == '-' || format[i] == '0')
			i += get_minus_zero_flag(args, format[i]);
		else if (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			i += get_plus_space_flag_hash(args, format[i]);
		else if (ft_isdigit(format[i]))
		{
			args->width = ft_atoi(format + i);
			i += ft_get_length(args->width, 10);
		}
		else if (format[i] == '*')
			i += get_wildcard(args, &(args->width), list, 1);
		else if (format[i] == '.' && !(args->set_precision))
			i += get_precision_flag(args, format + (i + 1), list);
		else if (ft_isalpha(format[i]) || format[i] == '%')
			i = get_alpha_flags(args, format, i);
		else
			i++;
	}
	return (i);
}
