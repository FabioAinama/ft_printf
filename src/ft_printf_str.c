#include "ft_printf.h"
#include "libft.h"

int		ft_putwstr(wchar_t *wstr)
{
	int		length;

	length = 0;
	while (*wstr)
	{
		ft_putwchar(*wstr);
		length += ft_wcharlen(*wstr);
		wstr++;
	}
	return (length);
}

int		ft_printf_wstr(t_printf_arg *args, va_list list)
{
	int		length;
	wchar_t	*str;
	wchar_t	*cpy;

	if (!(str = va_arg(list, wchar_t *)))
		str = ft_wstrdup(L"(null)");
	if (args->set_precision)
	{
		cpy = ft_wstrnew(args->precision);
		if (str)
			cpy = ft_wstrncpy(cpy, str, args->precision);
		str = cpy;
	}
	length = ft_wstrlen(str);
	args->length = length;
	if (!(args->flag_minus))
		length += ((args->width == 0) ? 0 : ft_deal_width(args));
	ft_putwstr(str);
	// free(str);
	if (args->flag_minus)
		length += ((args->width == 0) ? 0 : ft_deal_width(args));
	return (length);
}

int	ft_printf_str(t_printf_arg *args, va_list list)
{
	int		length;
	char	*str;
	char	*cpy;

	if (args->conv_s == 'l')
		return (ft_printf_wstr(args, list));
	if (!(str = va_arg(list, char *)))
		str = ft_strdup("(null)");
	if (args->set_precision)
	{
		cpy = ft_strnew(args->precision);
		if (str)
			cpy = ft_strncpy(cpy, str, args->precision);
		str = cpy;
	}
	length = ft_strlen(str);
	args->length = length;
	if (!(args->flag_minus))
		length += ((args->width == 0) ? 0 : ft_deal_width(args));
	ft_putstr(str);
	if (args->flag_minus)
		length += ((args->width == 0) ? 0 : ft_deal_width(args));
	return (length);
}

// int	ft_printf_str(t_printf_arg *args, va_list list)
// {
// 	int     i;
// 	int     length;
// 	int     precision;
// 	char    *str;

// 	i = -1;
// 	if (args->conv_s == 'l')
// 		return ft_printf_wstr(args, list);
// 	if (!(str = va_arg(list, char *)))
// 	{
// 		str =  ft_strdup("(null)");
// 		if (args->set_precision)
// 			return (0);
// 	}
// 	args->length = ft_strlen(str);
// 	precision = (args->precision == 0 ? args->length : args->precision);
// 	length = precision;
// 	if (!(args->flag_minus))
// 		length += ((args->width == 0) ? 0 : ft_deal_width(args));
// 	while (str[++i] && precision--)
// 		ft_putchar(str[i]);
// 	if (args->flag_minus)
// 		length += ((args->width == 0) ? 0 : ft_deal_width(args));
// 	return (length);
// }