/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:33:51 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 15:33:52 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_wchar(t_printf_arg *args, va_list list)
{
	int		length;
	wchar_t	c;

	c = va_arg(list, wint_t);
	if ((length = ft_wcharlen(c)) == -1)
		return (-1);
	args->length = length;
	if (!(args->fl_minus))
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	ft_putwchar(c);
	if (args->fl_minus)
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	return (length);
}

int	ft_printf_char(t_printf_arg *args, va_list list)
{
	int	length;

	if (args->conv_s)
		return (ft_printf_wchar(args, list));
	length = sizeof(char);
	args->length = length;
	if (!(args->fl_minus))
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	ft_putchar(va_arg(list, int));
	if (args->fl_minus)
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	return (length);
}
