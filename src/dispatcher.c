/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:56:32 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/20 14:56:35 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int				ft_dispatcher_else(t_printf_arg *args)
{
	int i;

	i = 0;
	if (args->type == 'Z')
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
	else if (args->type == '%')
		i = ft_print_petcent(args);
	return (i);
}

int				ft_dispatcher(t_printf_arg *args, va_list list, int ret)
{
	int i;

	setlocale(LC_ALL, "");
	i = 0;
	if (args->type == 's')
		i = ft_printf_str(args, list);
	else if (args->type == 'c')
		i = ft_printf_char(args, list);
	else if (args->type == 'd')
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
	else if (args->type == 'f')
		i = ft_printf_float(args, va_arg(list, double));
	else if (args->type == 'Z' || args->type == '%')
		i = ft_dispatcher_else(args);
	return (i == -1 ? i : ret + i);
}
