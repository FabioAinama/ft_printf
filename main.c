#include "includes/ft_printf.h"
// #include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int    main()
{
	// setlocale(LC_ALL, "");
	printf("F: %d\n", ft_printf("{%ls}\n", L"米"));
	printf("R: %d\n", printf("{%ls}\n", L"米"));
	// printf("F: %d\n", ft_printf("{%lc}\n", 945));
	// printf("R: %d\n", printf("{%lc}\n", 945));
	// printf("F: %d\n", ft_printf("{%lc}\n", 128));
	// printf("R: %d\n", printf("{%lc}\n", 128));
	// printf("F: %d\n", ft_printf("{%010.0f}\n", 42.6465424242242));
	// printf("R: %d\n", printf("{%010.0f}\n", 42.6465424242242));
	// printf("F: %d\n", ft_printf("{This is Yolo %s !}\n", ".Yeah it is"));
	// printf("R: %d\n", printf("{This is Yolo %s !}\n", ".Yeah it is"));

}