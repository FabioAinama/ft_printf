/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 05:11:48 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/14 05:11:49 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_deal_zero(t_printf_arg *args)
{
	int toprint;
	int printed;

	toprint = args->width - (args->fl_space || args->fl_plus || args->neg) \
		- args->length;
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
		if (args->fl_plus)
			ft_putchar('+');
		else if (args->fl_space)
			ft_putchar(' ');
	}
	else
		ft_putchar('-');
	return (1);
}

int	ft_deal_precision(t_printf_arg *args)
{
	int		toprint;
	int		printed;
	char	c;

	c = args->type;
	toprint = args->precision - args->length;
	if ((c == 'o') && args->fl_hash)
		toprint--;
	printed = (toprint > 0 ? toprint : 0);
	while (toprint > 0)
	{
		ft_putchar('0');
		toprint--;
	}
	return (printed);
}

int	ft_deal_hash(t_printf_arg *args, uintmax_t nb)
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

int	ft_deal_width(t_printf_arg *as)
{
	int	toprint;
	int	printed;

	toprint = as->width - as->precision - \
		(as->fl_space || as->fl_plus || as->neg) - as->length;
	if (as->fl_hash)
	{
		if (as->type == 'x' || as->type == 'X' || as->type == 'p')
			toprint -= 2;
		else if (as->type == 'o' || as->type == 'O')
			toprint--;
	}
	if ((as->type != 's' && as->type != 'f') && as->precision)
		toprint += ((as->precision > as->length) ? as->length : as->precision);
	else if (as->type == 's' && as->precision)
		toprint += ((as->precision > as->length) ? as->precision : as->length);
	printed = (toprint > 0 ? toprint : 0);
	while (toprint > 0)
	{
		(as->fl_zero) ? ft_putchar('0') : ft_putchar(' ');
		toprint--;
	}
	return (printed);
}
