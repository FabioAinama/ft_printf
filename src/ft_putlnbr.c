/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fginja-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 15:40:16 by fginja-d          #+#    #+#             */
/*   Updated: 2018/09/15 15:40:17 by fginja-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_putunbr(int n)
{
	unsigned int un;

	un = n;
	if (n < 0)
		un = -n;
	if (un > 9)
	{
		ft_putunbr(un / 10);
		ft_putchar(un % 10 + 48);
	}
	else
		ft_putchar(un + 48);
	return (ft_get_length(un, 10));
}

int		ft_putlunbr(uintmax_t n)
{
	if (n > 9)
	{
		ft_putlunbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
	return (ft_get_length(n, 10));
}

int		ft_putlnbr(intmax_t n)
{
	uintmax_t nb;

	if (n < 0)
		ft_putchar('-');
	nb = (n < 0 ? -n : n);
	if (nb > 9)
	{
		ft_putlunbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
	else
		ft_putchar(nb + 48);
	return (ft_get_length(nb, 10));
}
