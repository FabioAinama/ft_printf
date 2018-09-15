/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 05:15:57 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/12 05:16:00 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_should_i_print_dec(t_printf_arg *args, intmax_t nb)
{
	int i;

	if (args->precision == 0 && args->set_precision && !nb)
		return (0);
	else
	{
		if ((args->conv_s == 'j' || args->conv_s == 'z') && args->type == 'd')
			i = ft_putlunbr((unsigned long)nb);
		else if (args->conv_s == 'l' && args->type == 'u')
			i = ft_putlunbr((unsigned long)nb);
		else if (args->conv_s == 'l' && args->type == 'o')
			i = ft_putlunbr((unsigned long)nb);
		else if (args->conv_s == 'l' || args->type == 'u' || args->type == 'o')
			i = ft_putlunbr(nb);
		else
			i = ft_putunbr(nb);
	}
	return (i);
}

int	ft_deal_number(t_printf_arg *args, intmax_t nb)
{
	int i;

	i = 0;
	args->neg = (nb < 0 ? 1 : 0);
	nb = (nb < 0 ? -nb : nb);
	args->length = ft_get_length(nb, 10);
	if (args->precision == 0 && args->set_precision && !nb)
		args->length = 0;
	if ((args->fl_minus == 0) && (args->fl_zero == 0))
		i += ((args->width <= 0) ? 0 : ft_deal_width(args));
	if (args->fl_space || args->fl_plus || args->neg)
		i += ft_deal_plus_space(args);
	if (args->fl_zero)
		i += ft_deal_zero(args);
	if (args->precision)
		i += ft_deal_precision(args);
	i += ft_should_i_print_dec(args, nb);
	if (args->fl_minus)
		i += ((args->width <= 0) ? 0 : ft_deal_width(args));
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
