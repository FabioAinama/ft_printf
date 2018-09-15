/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:27:40 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 16:27:42 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_max_number(intmax_t size)
{
	int res;

	res = 0;
	while (size)
	{
		res *= 10;
		res += 9;
		size--;
	}
	return (res);
}

intmax_t	ft_round_float(double nb, int pcs, intmax_t *units, intmax_t rst)
{
	nb *= 10;
	if ((intmax_t)(nb + 0.00001) > 4)
	{
		if (rst == ft_max_number(pcs))
		{
			rst = 0;
			units++;
		}
		else
			rst++;
	}
	return (rst);
}

intmax_t	ft_get_float(t_printf_arg *args, double nb, intmax_t *units)
{
	intmax_t	float_sum;
	int			i;
	int			j;

	i = 0;
	float_sum = 0;
	nb = nb - (intmax_t)nb;
	nb *= (nb < 0 ? -1 : 1);
	while (i < args->precision)
	{
		float_sum *= 10;
		j = 9;
		nb *= 10;
		while (j > (nb + 0.00001))
			j--;
		float_sum += j;
		nb -= j;
		i++;
	}
	if (i == args->precision)
		float_sum = ft_round_float(nb, args->precision, units, float_sum);
	return (float_sum);
}

int			ft_printf_float(t_printf_arg *args, double nb)
{
	intmax_t	units;
	intmax_t	float_sum;
	int			length;
	int			ret;

	units = (intmax_t)nb;
	float_sum = ft_get_float(args, nb, &units);
	ret = (nb < 0 ? 1 : 0);
	args->length = ft_get_length(units, 10) + (args->precision ? 1 : 0);
	if (args->fl_minus == 0)
		ret += (args->width <= 0) ? 0 : ft_deal_width(args);
	if (args->fl_space || args->fl_plus || args->neg)
		ret += ft_deal_plus_space(args);
	ft_putlnbr(units);
	if (args->precision != 0)
		ft_putchar('.');
	length = args->precision - ft_get_length(float_sum, 10);
	while (length-- && length > 0)
		ft_putchar('0');
	(float_sum) ? ft_putnbr(float_sum) : 0;
	if (args->fl_minus)
		ret += (args->width <= 0) ? 0 : ft_deal_width(args);
	ret += ft_get_length(units, 10);
	ret += (args->precision > 0 ? args->precision + 1 : 0);
	return (ret);
}
