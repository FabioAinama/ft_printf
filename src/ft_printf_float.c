#include "ft_printf.h"
#include "libft.h"

unsigned int ft_max_number(int size)
{
	unsigned int res;

	res = 0;
	while (size)
	{
		res *= 10;
		res += 9;
		size--;
	}
	return (res);
}

void ft_printf_float(t_printf_arg *args, double nb)
{
	int i;
	int length;
	unsigned int float_sum;
	unsigned int units;
	int j;

	// printf("Largeur: %d\n", args->width);
	i = 0;
	float_sum = 0;
	units = (int)nb;
	nb = nb - (int)nb;
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
	{
		nb *= 10;         
		if ((int)(nb + 0.00001) > 4)
		{
			if (float_sum == ft_max_number(args->precision))
			{
				float_sum = 0;
				units++;
			}
			else
				float_sum++;
		}
	}
	args->length = ft_get_length(units, 10) + (args->precision ? 1 : 0);
	if (args->flag_minus == 0)
		args->width == 0 ? 0 : ft_deal_width(args);
	ft_putnbr(units);
	if (args->precision != 0)
		ft_putchar('.');
	length = args->precision - ft_get_length(float_sum, 10);
	while (length--)
		ft_putchar('0');
	if (float_sum)
		ft_putnbr(float_sum);
	if (args->flag_minus)
		args->width == 0 ? 0 : ft_deal_width(args);
}
