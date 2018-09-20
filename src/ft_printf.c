/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:59:53 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 16:59:55 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf_arg	*new_printf_args(void)
{
	t_printf_arg *args;

	if (!(args = (t_printf_arg*)malloc(sizeof(t_printf_arg))))
		return (NULL);
	args->fl_minus = 0;
	args->fl_plus = 0;
	args->fl_space = 0;
	args->fl_hash = 0;
	args->fl_zero = 0;
	args->precision = 0;
	args->set_precision = 0;
	args->neg = 0;
	args->length = 0;
	args->type = 0;
	args->type = 0;
	args->conv_s = 0;
	args->conv_d = 0;
	args->width = 0;
	return (args);
}

void			ft_printf_else(char c, int *i, int *ret)
{
	ft_putchar(c);
	(*ret)++;
	(*i)++;
}

int				ft_printf(const char *format, ...)
{
	int				i;
	int				ret;
	va_list			list;
	t_printf_arg	*args;

	i = 0;
	ret = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (!(args = new_printf_args()))
				return (-1);
			i += get_flags(args, (format + i), list);
			if ((ret = ft_dispatcher(args, list, ret)) == -1)
				return (-1);
			free(args);
		}
		else
			ft_printf_else(format[i], &i, &ret);
	}
	va_end(list);
	return (ret);
}
