/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:37:05 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 15:37:06 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf_wstr(t_printf_arg *args, va_list list)
{
	int		length;
	wchar_t	*str;
	wchar_t	*val;
	wchar_t	*cpy;

	val = va_arg(list, wchar_t *);
	str = (val ? ft_wstrdup(val) : ft_wstrdup(L"(null)"));
	if (args->set_precision == 1)
	{
		cpy = ft_wstrnew(args->precision);
		if (str)
			cpy = ft_wstrncpy(cpy, str, args->precision);
		str = cpy;
	}
	length = ft_wstrlen(str);
	args->length = length;
	if (!(args->fl_minus))
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	ft_putwstr(str);
	free(str);
	if (args->fl_minus)
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	return (length);
}

int	ft_printf_str(t_printf_arg *args, va_list list)
{
	int		length;
	char	*str;
	char	*val;
	char	*cpy;

	if (args->conv_s == 'l')
		return (ft_printf_wstr(args, list));
	val = va_arg(list, char *);
	str = (val ? ft_strdup(val) : ft_strdup("(null)"));
	if (args->set_precision == 1)
	{
		cpy = ft_strnew(args->precision);
		if (str)
			cpy = ft_strncpy(cpy, str, args->precision);
		str = cpy;
	}
	length = ft_strlen(str);
	args->length = length;
	if (!(args->fl_minus))
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	ft_putstr(str);
	free(str);
	if (args->fl_minus)
		length += ((args->width <= 0) ? 0 : ft_deal_width(args));
	return (length);
}
