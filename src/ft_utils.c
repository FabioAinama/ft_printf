#include "ft_printf.h"
#include "libft.h"

int		ft_isupper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		ft_islower(char c)
{
	if (c >= 'a' && c <= 'x')
		return (1);
	return (0);
}

char	*ft_strrev(char *str)
{
	char tmp;	
	int i;
	int length;

	i = 0;
	length = ft_strlen(str) - 1;
	while (i < (length - i))
	{
		tmp = str[i];
		str[i] = str[(length) - i];
		str[(length) - i] = tmp;
		i++;
	}
	// free(tmp);
	return (str);
}

int		ft_wcharlen(wchar_t wchar)
{
	int	length;

	length = 0;
	if (wchar <= 0xFF)
		length = 1;
	else if (wchar < 0x0800)
		length = 2;
	else if (wchar < 0x010000)
		length = 3;
	else if (wchar < 0x110000)
		length = 4;
	else
		length = -1;
	return (length);
}

void	ft_print_all_flags(t_printf_arg *args)
{
    printf("'#': %d\n'-': %d\n'+': %d\n' ': %d\n'0': %d\n'.': %d\nSetPrecision: %d\nLength: %d\nIsNeg: %d\nType: %c\nNoType: %c\nConversion1: %c\nConversion2: %c\nWidth: %d\n",args->fl_hash, args->fl_minus, args->fl_plus, args->fl_space, args->fl_zero, args->precision, args->set_precision, args->length, args->neg, args->type, args->notype, args->conv_s, args->conv_d, args->width);
}

size_t	ft_wstrlen(const wchar_t *wstr)
{
	size_t	i;

	i = 0;
	while (*wstr)
	{
		i += ft_wcharlen(*wstr);
		wstr++;
	}
	return (i);
}

wchar_t		*ft_wstrcpy(wchar_t *dst, const wchar_t *src)
{
	size_t	i;

	i = 0;
	while ((dst[i] = src[i]) != L'\0')
		i += 1;
	return (dst);
}

wchar_t	*ft_wstrdup(wchar_t *src)
{
	int		length;
	wchar_t	*dst;

	length = ft_wstrlen(src) + sizeof(wchar_t);
	dst = ft_memalloc(sizeof(wchar_t) * length);
	if (dst)
		ft_wstrcpy(dst, src);
	return (dst);
}

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t	*wstr;

	wstr = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (wstr);
}

wchar_t		*ft_wstrncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_wstrlen(src);
	while (i < len)
	{
		dst[i] = src[i];
		i += ft_wcharlen(src[i]);
	}
	while (length < len)
	{
		dst[length] = L'\0';
		length++;
	}
	return (dst);
}