#include "ft_printf.h"
#include "libft.h"

int get_alpha_flags(t_printf_arg *args, const char *format, int i)
{
	char c;

	// Cas d'erreur ou flag déjà défini: je retourne 1, a voir si ok
	// if (args->type && args->type != 'Z')
	if (args->type)
		return (i + 1);
	c = format[i];
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		i = get_conv_flags(args, format, i);

	// Type
	if (format[i] == 'i' || format[i] == 'd' || format[i] == 'D')
	{
		args->type = 'd';
		(format[i] == 'D') ? args->conv_s = 'l' : 0;
		(args->precision < 0) ? args->precision = 0 : 0;
		(args->precision) ? args->flag_zero = 0 : 0;
	}
	else if (format[i] == 's' || format[i] == 'S')
	{
		(format[i] == 'S') ? args->conv_s = 'l' : 0;
		// args->flag_zero = 0;
		args->flag_plus = 0;
		args->flag_space = 0;
		(args->precision < 0) ? args->precision *= -1 : 0;		
		args->type = 's';
	}
	else if (format[i] == 'f' || format[i] == 'F')
	{
		(format[i] == 'F') ? args->conv_s = 'l' : 0;		
		(args->set_precision == 0) ? args->precision = 6 : 0;
		args->type = 'f';
	}
	else if (format[i] == 'o' || format[i] == 'O' || format[i] == 'u' || format[i] == 'U')
	{
		(ft_isupper(format[i])) ?	args->conv_s = 'l' : 0;
		args->flag_plus = 0;
		args->flag_space = 0;
		args->type = ft_tolower(format[i]);
	}
	else if (format[i] == 'x' || format[i] == 'X')
	{
		args->flag_plus = 0;
		args->flag_space = 0;
		// args->precision = 0;
		args->type = format[i];
	}
	else if (format[i] == 'c' || format[i] == 'C')
	{
		(format[i] == 'C') ? args->conv_s = 'l' : 0;
		args->type = 'c';
	}
	else if (format[i] == '%')
		args->type = '%';
	else if (format[i] == 'p')
	{
		args->type = 'p';
		args->flag_hash = 1;
	}
	else
	{
		args->type = 'Z';
		args->notype = format[i];
		// return (i);
	}
	// i à incrémenter ici
	// printf("Alpha Format i: %c\n", format[i]);
	return (i + 1); 
}