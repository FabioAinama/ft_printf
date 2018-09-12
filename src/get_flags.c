#include "ft_printf.h"
#include "libft.h"

int get_alpha_flags(t_printf_arg *args, const char *format, int i)
{
	// Cas d'erreur ou flag déjà défini: je retourne 1, a voir si ok
	if (args->type)
		return (i + 1);
	if (format[i] == 'l')
	{
		(!args->conv_d && args->conv_s == 'l') ? args->conv_d = 'l' : 0;
		(!args->conv_s) ? args->conv_s = 'l' : 0;
	}
	else if (format[i] == 'h')
	{
		(!args->conv_d && args->conv_s == 'h') ? args->conv_d = 'h' : 0;
		(!args->conv_s) ? args->conv_s = 'h' : 0;	
	}
	else if (format[i] == 'j' || format[i] == 'z')
	{
		args->conv_s = format[i];
	}
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
	// i à incrémenter ici
	// printf("Alpha Format i: %c\n", format[i]);
	return (i + 1); 
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
	while (!(args->type) && format[i])
	{
		// printf("Format: %s", format + i);
		// printf("Type: %c\n", args->type);
		if (format[i] == '-' || format[i] == '0')
			i = get_minus_zero_flag(args, format, i);
		else if (format[i] == '+' || format[i] == ' ')
			i = get_plus_space_flag(args, format, i);
		else if (format[i] == '#')
		{
			args->flag_hash = 1;
			i++;
		}
		else if (ft_isdigit(format[i]) && !(args->width))
		{
			args->width = ft_atoi(format + i);
			i += ft_get_length(args->width, 10);
		}
		else if (format[i] == '.' && !(args->set_precision))
		{
			// printf("Format i: %c\n", format[i + 1]);			
			if (format[++i] >= '0' && format[i] <= '9')
			{
				args->precision = ft_atoi(format + i);
				i += ft_get_length(args->precision, 10);
			}
			else
				args->precision = 0;
			// printf("Format i: %c, atoi: %d, precision: %d\n", format[i], ft_atoi(format + i), args->precision);
			args->set_precision = 1;
			// i += (args->precision ? ft_get_length(args->precision, 10) : 0);
		}
		else if (ft_isalpha(format[i]) || format[i] == '%')
			i = get_alpha_flags(args, format, i);
		else
			i++;
		// Si char incompatible, boucle infinie !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	// No specifier
	// if ((args->type) && format[i] == '\n')
	// {
	// 	i = 0;
	// 	while (format[i] == ' ')
	// 		i++;
	// 	ft_putstr(format + i);
	// 	return (ft_strlen(format + i));
	// }
	// printf("Valeur de i (inside get_flag): %d, Char: %c\n", i - 1, format[i - 1]);
	return (i);
}
