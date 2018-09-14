#include "ft_printf.h"
#include "libft.h"

char *ft_convert_base_str(uintmax_t nb, int base)
{
	char *converted;
	int length;
	uintmax_t tmp;

	length = ((!nb) ? 1 : 0);
	length += ft_get_un_length(nb, base);
	if (!(converted = ft_strnew(length)))
		return (NULL);
	converted[0] = '0';
	length = ((!nb) ? 1 : 0);
	while (nb)
	{
		tmp = nb % base;
		nb /= base;
		converted[length] = tmp + '0';
		length++;
	}
	converted[length] = '\0';
	converted = ft_strrev(converted);
	return (converted);
}

char *ft_convert_neg_binary(char *binary)
{
	int i;

	i = 0;
	while(binary[i])
	{
		if (binary[i] == '0')
			binary[i] = '1';
		else
			binary[i] = '0';
		i++;
	}
	i = 0;
	while (binary[i] == '1')
	{
		binary[i] = '0';
		i++;
	}
	if (binary[i])
		binary[i] = '1';
	return (binary);
}

// int ft_binary_to_int(char *binary)
// {
// 	int length;
// 	int i;
// 	int sum;

// 	length = 1;
// 	i = 0;
// 	sum = 0;
// 	while (binary[i])
// 	{
// 		sum += ((binary[i] - 48) * length);
// 		i++;
// 		length *= 2;
// 	}
// 	return (sum);
// }

uintmax_t ft_binary_to_int(char *binary)
{
	int length;
	int i;
	uintmax_t sum;

	if ((length = ft_strlen(binary)) == 0)
		return (0);
	i = 1;
	sum = 0;
	while (binary[--length])
	{
		sum += ((binary[length] - 48) * i);
		i *= 2;
	}
	return (sum);
}

int ft_printf_conv_binary(t_printf_arg *args, char *binary)
{
	uintmax_t nb;

	nb = ft_binary_to_int(binary);
	return (ft_deal_number(args, nb));
}

// char *ft_convert_binary(t_printf_arg *args, int nb)
// {
// 	char *binary;
// 	int i;
// 	int length;

// 	length = 32;
// 	binary = ft_strnew(length);
// 	i = -1;
// 	while (++i < length)
// 		binary[i] = '0';
// 	i = 0;
// 	nb = (nb < 0 ? -nb : nb);
// 	while (nb)
// 	{
// 		binary[i] = ((nb % 2) + '0');
// 		// printf("i: %d, c: %c, nb%%2: %d\n", i, binary[i], (nb % 2));
// 		nb /= 2;
// 		i++;
// 	}
// 	binary[i] = '\0';

// 	// if (nb < 0)
// 	ft_convert_neg_binary(binary);
// 	unsigned int sum = ft_binary_to_int(binary);
// 	// ft_deal_number2(args, ft_convert_base_hexa(sum, args->type));	
// }

