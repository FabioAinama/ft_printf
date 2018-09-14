/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 04:57:26 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/14 04:57:27 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	get_minus_zero_flag(t_printf_arg *args, const char c)
{
	if (c == '-')
	{
		args->fl_minus = 1;
		args->fl_zero = 0;
	}
	if (c == '0' && !(args->fl_minus))
		args->fl_zero = 1;
	return (1);
}

int	get_plus_space_flag_hash(t_printf_arg *args, const char c)
{
	if (c == '#')
		args->fl_hash = 1;
	if (c == '+')
	{
		args->fl_plus = 1;
		args->fl_space = 0;
	}
	if (c == ' ' && !(args->fl_plus))
		args->fl_space = 1;
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
			args->fl_minus = 1;
		}
	}
	*ptr = nb;
	return (1);
}

int	get_precision_flag(t_printf_arg *args, const char *format, va_list list)
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

int	get_flags(t_printf_arg *args, const char *format, va_list list)
{
	int i;
	int notype;

	i = 0;
	notype = 0;
	while (!(args->type) && format[i])
	{
		if (format[i] == '-' || format[i] == '0')
			i += get_minus_zero_flag(args, format[i]);
		else if (format[i] == '+' || format[i] == ' ' || format[i] == '#')
			i += get_plus_space_flag_hash(args, format[i]);
		else if (ft_isdigit(format[i]) && (ft_atoi(format + i) > 0))
		{
			args->width = ft_atoi(format + i);
			i += ft_get_length(args->width, 10);
		}
		else if (format[i] == '*')
			i += get_wildcard(args, &(args->width), list, 1);
		else if (format[i] == '.')
			i += get_precision_flag(args, format + (i + 1), list);
		else if (ft_isalpha(format[i]) || format[i] == '%')
			i = get_alpha_flags(args, format, i);
		else
			return (i);
	}
	return (i);
}
