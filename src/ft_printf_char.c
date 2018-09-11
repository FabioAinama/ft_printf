#include "ft_printf.h"
#include "libft.h"

int	ft_convert_wchar(wchar_t wchar, char *converted)
{
	int	length;

	length = 0;
	if (wchar <= 0xFF)
		converted[length++] = wchar;
	else if (wchar < 0x0800)
	{
		converted[length++] = ((wchar >> 6) & 0x1F) | 0xC0;
		converted[length++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x010000)
	{
		converted[length++] = ((wchar >> 12) & 0x0F) | 0xE0;
		converted[length++] = ((wchar >> 6) & 0x3F) | 0x80;
		converted[length++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x110000)
	{
		converted[length++] = ((wchar >> 18) & 0x07) | 0xF0;
		converted[length++] = ((wchar >> 12) & 0x3F) | 0x80;
		converted[length++] = ((wchar >> 6) & 0x3F) | 0x80;
		converted[length++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	return (length);
}

int	ft_putwchar(wchar_t wchar)
{
    char	*converted;
    int		length;

    converted = ft_strnew(4);
	length = ft_convert_wchar(wchar, converted);
	write(1, converted, length);
	return (length);
}

int	ft_printf_wchar(t_printf_arg *args, va_list list)
{
	int		length;
	wchar_t	c;

	c = va_arg(list, wint_t);
	length = ft_wcharlen(c);
	args->length = length;	
	if (!(args->flag_minus))
		length = ft_deal_width(args);
	ft_putwchar(c);
	if (args->flag_minus)
		length = ft_deal_width(args);
	return (length);
}

int	ft_printf_char(t_printf_arg *args, va_list list)
{
	int	length;

	if (args->conv_s)
		return (ft_printf_wchar(args, list));
	length = sizeof(char);
	args->length = length;
	if (!(args->flag_minus))
		length = ft_deal_width(args);
	ft_putchar(va_arg(list, int));
	if (args->flag_minus)
		length = ft_deal_width(args);
	return (length);
}