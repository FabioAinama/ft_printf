#include "ft_printf.h"

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