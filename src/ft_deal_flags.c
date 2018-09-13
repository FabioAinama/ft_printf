#include "ft_printf.h"
#include "libft.h"

int	ft_deal_zero(t_printf_arg *args)
{
	int toprint;
	int printed;

	toprint = args->width - (args->flag_space || args->flag_plus || args->neg) - args->length;
	// if (args->neg)
	// 	toprint--;
	printed = (toprint > 0 ? toprint : 0);
	while (toprint > 0)
	{
		ft_putchar('0');
		toprint--;
	}
	return (printed);
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
	char c;

	c = args->type;
	toprint = args->precision - args->length;
	if ((c == 'o') && args->flag_hash)
		toprint--;
	printed = (toprint > 0 ? toprint : 0);
	while (toprint > 0)
	{
		ft_putchar('0');
		toprint--;
	}
	return (printed);
}

int ft_deal_hash(t_printf_arg *args, uintmax_t nb)
{
	char c;

	c = args->type;
	if ((c == 'x' || c == 'X' || c == 'o') && !(nb))
		return (0);
	ft_putchar('0');
	if (c == 'x' || c == 'X' || c == 'p')
	{
		(c == 'X') ? ft_putchar(c) : ft_putchar('x');
		return (2);
	}
	return (1);
}

int	ft_deal_width(t_printf_arg *args)
{
	int	toprint;
	int	printed;

	toprint = args->width - args->precision - (args->flag_space || args->flag_plus || args->neg) - args->length;
	// ft_print_all_flags(args);
	// printf("Toprint: %d\n", toprint);
	if (args->flag_hash)
	{
		if (args->type == 'x' || args->type == 'X' || args->type == 'p')
			toprint -= 2;
		else if (args->type == 'o' || args->type == 'O')
			toprint--;
	}
	if ((args->type != 's' && args->type != 'f') && args->precision)
		toprint += ((args->precision > args->length) ? args->length : args->precision);
	else if (args->type == 's' && args->precision)
		toprint += ((args->precision > args->length) ? args->precision : args->length);
	printed = (toprint > 0 ? toprint : 0);
	// printf("Toprint: %d\n", toprint);
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
