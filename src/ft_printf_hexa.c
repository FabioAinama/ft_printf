/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 05:22:13 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/12 05:22:17 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_get_length(intmax_t nb, int base)
{
	int	length;

	if (!nb)
		return (1);
	length = 0;
	while (nb)
	{
		nb /= base;
		length++;
	}
	return (length);
}

int		ft_get_un_length(uintmax_t nb, int base)
{
	int length;

	if (!nb)
		return (1);
	length = 0;
	while (nb)
	{
		nb /= base;
		length++;
	}
	return (length);
}

char	*ft_convert_base_hexa(uintmax_t nb, char base)
{
	int			size;
	uintmax_t	tmp;
	char		*res;
	char		*hexa;

	if (base == 'X')
		hexa = ft_strdup("0123456789ABCDEF");
	else
		hexa = ft_strdup("0123456789abcdef");
	tmp = nb;
	size = ((!nb) ? 1 : 0);
	size += ft_get_un_length(nb, 16);
	res = ft_strnew(size);
	if (!nb)
		res[0] = '0';
	while (nb)
	{
		res[--size] = hexa[nb % 16];
		nb /= 16;
	}
	free(hexa);
	return (res);
}

int		ft_printf_hexa(t_printf_arg *args, va_list list)
{
	int i;

	i = 0;
	if (args->type == 'p')
		i += ft_deal_nbr_str(args, (uintmax_t)va_arg(list, void *), 16);
	else if (args->conv_s == 'j')
		i += ft_deal_nbr_str(args, va_arg(list, uintmax_t), 16);
	else if (args->conv_s == 'z')
		i += ft_deal_nbr_str(args, va_arg(list, size_t), 16);
	else if (args->conv_s == 'l' && args->conv_d == 'l')
		i += ft_deal_nbr_str(args, va_arg(list, unsigned long long), 16);
	else if (args->conv_s == 'l')
		i += ft_deal_nbr_str(args, va_arg(list, unsigned long), 16);
	else if (args->conv_s == 'h' && args->conv_d == 'h')
		i += ft_deal_nbr_str(args, \
		(unsigned char)va_arg(list, unsigned int), 16);
	else if (args->conv_s == 'h')
		i += ft_deal_nbr_str(args, \
		(unsigned short)va_arg(list, unsigned int), 16);
	else
		i += ft_deal_nbr_str(args, va_arg(list, unsigned int), 16);
	return (i);
}
