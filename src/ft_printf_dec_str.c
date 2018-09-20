/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:48:12 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 15:48:14 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_should_i_print(char *str, t_printf_arg *args, uintmax_t nb)
{
	char c;

	c = args->type;
	if ((args->precision == 0 && args->set_precision && !nb) \
		&& !(c == 'o' && args->fl_hash))
	{
		if (args->width)
		{
			ft_putchar(' ');
			return (1);
		}
		return (0);
	}
	ft_putstr(str);
	return (args->length);
}

int	ft_deal_nbr_str(t_printf_arg *args, uintmax_t nb, int base)
{
	int		i;
	char	*str_nb;

	i = 0;
	if (args->type == 'x' || args->type == 'X' || args->type == 'p')
		str_nb = ft_convert_base_hexa(nb, args->type);
	else
		str_nb = ft_convert_base_str(nb, base);
	if (!str_nb)
		return (0);
	args->length = ft_strlen(str_nb);
	if (args->fl_hash && args->fl_zero)
		i += ft_deal_hash(args, nb);
	if (args->fl_minus == 0)
		i += ((args->width <= 0) ? 0 : ft_deal_width(args));
	if (args->fl_hash && !(args->fl_zero))
		i += ft_deal_hash(args, nb);
	if (args->precision)
		i += ft_deal_precision(args);
	i += ft_should_i_print(str_nb, args, nb);
	free(str_nb);
	if (args->fl_minus)
		i += ((args->width <= 0) ? 0 : ft_deal_width(args));
	return (i);
}

int	ft_printf_udecimal(t_printf_arg *args, va_list list)
{
	int i;

	i = 0;
	if (args->conv_s == 'j')
		i += ft_deal_nbr_str(args, va_arg(list, uintmax_t), 10);
	else if (args->conv_s == 'z')
		i += ft_deal_nbr_str(args, va_arg(list, size_t), 10);
	else if (args->conv_s == 'l' && args->conv_d == 'l')
		i += ft_deal_nbr_str(args, va_arg(list, unsigned long long), 10);
	else if (args->conv_s == 'l')
		i += ft_deal_nbr_str(args, va_arg(list, unsigned long), 10);
	else if (args->conv_s == 'h' && args->conv_d == 'h')
		i += ft_deal_nbr_str(args, \
			(unsigned char)va_arg(list, unsigned int), 10);
	else if (args->conv_s == 'h')
		i += ft_deal_nbr_str(args, \
			(unsigned short)va_arg(list, unsigned int), 10);
	else
		i += ft_deal_nbr_str(args, va_arg(list, unsigned int), 10);
	return (i);
}
