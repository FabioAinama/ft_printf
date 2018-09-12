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

int	ft_deal_number(t_printf_arg *args, intmax_t nb)
{
	int i;

	// printf("Nb recu: %ld\n", nb);
	i = 0;
	args->length = ft_get_length(nb, 10);
	args->neg = (nb < 0 ? 1 : 0);
	nb = (nb < 0 ? -nb : nb);
	if (args->flag_minus == 0 && !(args->type == 'd' && args->flag_zero == 1))
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
	if (args->flag_space || args->flag_plus || args->neg)
		i += ft_deal_plus_space(args);
	if (args->flag_zero)
		i += ft_deal_zero(args);
	if (args->precision)
		i += ft_deal_precision(args);
	if ((args->conv_s == 'j' || args->conv_s == 'z') && args->type == 'd')
		i += ft_putlunbr((unsigned long)nb);	
	else if (args->conv_s == 'l' && args->type == 'u')
		i += ft_putlunbr((unsigned long)nb);
	else if (args->conv_s == 'l' && args->type == 'o')
		i += ft_putlunbr((unsigned long)nb);
	else if (args->conv_s == 'l' || args->type == 'u' || args->type == 'o')
		i += ft_putlunbr(nb);
	else
		i += ft_putunbr(nb);
	if (args->flag_minus)
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
	return (i);
}

int	ft_should_i_print(char *str, t_printf_arg *args, uintmax_t nb)
{
	if (args->precision == 0 && args->set_precision && !nb)
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
	if (args->type == 'x' || args->type == 'X')
		str_nb = ft_strdup(ft_convert_base_hexa(nb, args->type));
	else
		str_nb = ft_strdup(ft_convert_base_str(nb, base));
	args->length = ft_strlen(str_nb);
	if (args->flag_hash && args->flag_zero)
		i += ft_deal_hash(args, nb);
	if (args->flag_minus == 0)
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
	if (args->precision)
		i += ft_deal_precision(args);
	if (args->flag_hash && !(args->flag_zero))
		i += ft_deal_hash(args, nb);
	i += ft_should_i_print(str_nb, args, nb);
	free(str_nb);
	if (args->flag_minus)
		i += ((args->width == 0) ? 0 : ft_deal_width(args));
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
	{
		// printf("Long Called\n");
		i = ft_deal_number(args, va_arg(list, long));
	}
	else if (args->conv_s == 'h' && args->conv_d == 'h')
		i = ft_deal_number(args, (char)va_arg(list, int));
	else if (args->conv_s == 'h')
		i = ft_deal_number(args, (short)va_arg(list, int));
	else
		i = ft_deal_number(args, va_arg(list, int));
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
		i += ft_deal_nbr_str(args, (unsigned char)va_arg(list, unsigned int), 10);
	else if (args->conv_s == 'h')
		i += ft_deal_nbr_str(args, (unsigned short)va_arg(list, unsigned int), 10);
	else
		i += ft_deal_nbr_str(args, va_arg(list, unsigned int), 10);
	return (i);
}
