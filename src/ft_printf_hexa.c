#include "ft_printf.h"
#include "libft.h"

char *ft_convert_base_hexa(uintmax_t nb, char base)
{
	int size;
	uintmax_t tmp;
	char *res;
	char *hexa;

	hexa = (base != 'l' ? ft_strdup("0123456789abcdef") : ft_strdup("0123456789ABCDEF"));	
	tmp = nb;
	size = ((!nb) ? 1 : 0);
	while (tmp)
	{	
		tmp /= 16;
		size++;
	}
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

int	ft_printf_hexa(t_printf_arg *args, va_list list)
{
	int i;

	i = 0;
	if (args->type == 'p')
		i += ft_deal_number_str(args, (uintmax_t)va_arg(list, void *), 16);
	else if (args->conv_s == 'j')
		i += ft_deal_number_str(args, va_arg(list, uintmax_t), 16);
	else if (args->conv_s == 'z')
		i += ft_deal_number_str(args, va_arg(list, size_t), 16);
	else if (args->conv_s == 'l' && args->conv_d == 'l')
		i += ft_deal_number_str(args, va_arg(list, unsigned long long), 16);
	else if (args->conv_s == 'l')
		i += ft_deal_number_str(args, va_arg(list, unsigned long), 16);
	else if (args->conv_s == 'h' && args->conv_d == 'h')
		i += ft_deal_number_str(args, (unsigned short)va_arg(list, unsigned int), 16);
	else if (args->conv_s == 'h')
		i += ft_deal_number_str(args, (unsigned char)va_arg(list, unsigned int), 16);
	else
		i += ft_deal_number_str(args, va_arg(list, unsigned int), 16);
	return (i);
}