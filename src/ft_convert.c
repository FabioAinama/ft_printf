/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:25:30 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 15:25:32 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*ft_convert_base_str(uintmax_t nb, int base)
{
	char		*converted;
	int			length;
	uintmax_t	tmp;

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

char		*ft_convert_neg_binary(char *binary)
{
	int	i;

	i = 0;
	while (binary[i])
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

uintmax_t	ft_binary_to_int(char *binary)
{
	int			length;
	int			i;
	uintmax_t	sum;

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

int			ft_printf_conv_binary(t_printf_arg *args, char *binary)
{
	uintmax_t nb;

	nb = ft_binary_to_int(binary);
	return (ft_deal_number(args, nb));
}
