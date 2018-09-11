#include "ft_printf.h"

int get_alpha_flags(t_printf_arg *args, const char *format, int i)
{
	// Cas d'erreur ou flag déjà défini à gérer
	if (format[i] == 'l')
	{
		(!args->conv_s) ? args->conv_s = 'l' : 0;
		(!args->conv_d && args->conv_s == 'l') ? args->conv_d = 'l' : 0;
	}
	else if (format[i] == 'h')
	{
		(!args->conv_s) ? args->conv_s = 'h' : 0;
		(!args->conv_d && args->conv_s == 'h') ? args->conv_d = 'h' : 0;	
	}
	else if (format[i] == 'j' || format[i] == 'z')
		args->conv_s = format[i];
	// Type
	if (format[i] == 'i' || format[i] == 'd' || format[i] == 'D')
	{
		args->type = 'd';
		(format[i] == 'D') ? args->conv_s = 'l' : 0;
		(args->precision) ? args->flag_zero = 0 : 0;
	}
	else if (format[i] == 's' || format[i] == 'S')
	{
		(format[i] == 'S') ? args->conv_s = 'l' : 0;
		args->flag_zero = 0;
		args->flag_plus = 0;
		args->flag_space = 0;
		args->type = 's';
	}
	else if (format[i] == 'f' || format[i] == 'F')
	{
		(format[i] == 'F') ? args->conv_s = 'l' : 0;		
		(args->set_precision == 0) ? args->precision = 6 : 0;
		args->type = 'f';        
	}
	else if (format[i] == 'o' || format[i] == 'O' || format[i] == 'u' || format[i] == 'U' || format[i] == 'x' || format[i] == 'X')
	{
		(ft_isupper(format[i])) ?	args->conv_s = 'l' : 0;
		args->flag_plus = 0;
		args->flag_space = 0;
		args->type = ft_tolower(format[i]);
	}
	else if (format[i] == 'c' || format[i] == 'C')
	{
		(format[i] == 'C') ? args->conv_s = 'l' : 0;		
		args->type = 'c';
	}
	return (i); 
	// i à incrémenter ici
}

int get_minus_zero_flag(t_printf_arg *args, const char *format, int i)
{
	if (format[i] == '-')
	{
		args->flag_minus = 1;
		args->flag_zero = 0;
	}
	if (format[i] == '0' && !(args->flag_minus))
		args->flag_zero = 1;
	return (++i);
}

int get_plus_space_flag(t_printf_arg *args, const char *format, int i)
{
	if (format[i] == '+')
	{
		args->flag_plus = 1;
		args->flag_space = 0;
	}
	if (format[i] == ' ' && !(args->flag_plus))
		args->flag_space = 1;
	return (++i);
}

int get_flags(t_printf_arg *args, const char *format)
{
	int i;

	i = 0;
	// Incrementer i apres set width et set precision
	while (!(args->type) && format[i])
	{
		if (format[i] == '-' || format[i] == '0')
			i = get_minus_zero_flag(args, format, i);
		if (format[i] == '+' || format[i] == ' ')
			i = get_plus_space_flag(args, format, i);
		if (format[i] == '#')
			args->flag_hash = 1;
		if (ft_isdigit(format[i]) && !(args->width))
			args->width = ft_atoi(format + i);
		if (format[i] == '.')
		{
			if (format[++i] >= '0' && format[i] <= '9')
				args->precision = ft_atoi(format + i);
			else
				args->precision = 0;
			args->set_precision = 1;
		}
		if (ft_isalpha(format[i]))
			i = get_alpha_flags(args, format, i);
		i++;
	}
	return (i);
}
