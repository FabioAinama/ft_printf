/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alpha_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:55:38 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 16:55:39 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	set_dec_float_flag(t_printf_arg *args, char type)
{
	if (type == 'i' || type == 'd' || type == 'D')
	{
		args->type = 'd';
		(type == 'D') ? args->conv_s = 'l' : 0;
		if (args->precision < 0)
		{
			args->precision = 0;
			args->set_precision = 0;
		}
		(args->set_precision == 1) ? args->fl_zero = 0 : 0;
		(args->precision != 0) ? args->fl_zero = 0 : 0;
	}
	else if (type == 'f' || type == 'F')
	{
		(type == 'F') ? args->conv_s = 'l' : 0;
		(args->set_precision == 0) ? args->precision = 6 : 0;
		args->type = 'f';
	}
}

void	set_string_c_flag(t_printf_arg *args, char type)
{
	if (type == 's' || type == 'S')
	{
		(type == 'S') ? args->conv_s = 'l' : 0;
		args->fl_plus = 0;
		args->fl_space = 0;
		(args->precision < 0) ? args->precision *= -1 : 0;
		args->type = 's';
	}
	else if (type == 'c' || type == 'C')
	{
		(type == 'C') ? args->conv_s = 'l' : 0;
		args->type = 'c';
	}
}

void	set_poxu_flag(t_printf_arg *args, char type)
{
	args->fl_plus = 0;
	args->fl_space = 0;
	if (type != 'x' && type != 'X')
	{
		(ft_isupper(type) == 1) ? args->conv_s = 'l' : 0;
		type = ft_tolower(type);
	}
	if (type == 'p')
		args->fl_hash = 1;
	args->type = type;
}

int		get_conv_flags(t_printf_arg *args, const char *format, int i)
{
	char c;

	c = format[i];
	while (c == 'l' || c == 'h' || c == 'j' || c == 'z')
	{
		args->conv_d = 0;
		if (c == 'l')
		{
			(!args->conv_d && args->conv_s == 'l') ? args->conv_d = 'l' : 0;
			(!args->conv_s) ? args->conv_s = 'l' : 0;
		}
		else if (c == 'h')
		{
			(!args->conv_d && args->conv_s == 'h') ? args->conv_d = 'h' : 0;
			(!args->conv_s) ? args->conv_s = 'h' : 0;
		}
		else if (c == 'j' || c == 'z')
			args->conv_s = format[i];
		c = format[++i];
	}
	return (i);
}

int		get_alpha_flags(t_printf_arg *args, const char *format, int i)
{
	char c;

	if (args->type)
		return (i + 1);
	c = format[i];
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (get_conv_flags(args, format, i));
	if (c == 'i' || c == 'd' || c == 'D' || c == 'f' || c == 'F')
		set_dec_float_flag(args, c);
	else if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		set_string_c_flag(args, c);
	else if (c == 'o' || c == 'O' || c == 'u' || c == 'U' \
		|| c == 'x' || c == 'X' || c == 'p' || c == 'b' || c == 'q')
		set_poxu_flag(args, c);
	else if (c == '%')
		args->type = '%';
	else
	{
		args->type = 'Z';
		(ft_islower(c) == 0) ? args->notype = c : 0;
	}
	return (i + 1);
}
