#include "includes/ft_printf.h"
// #include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int    main()
{
    char *s1;
    char *s2;
    char s3;
    char *s4;
    int i;
    unsigned int ui = 1284;
    double dbl = 42.1325437;
    double dbl2 = 49.999999999995;
    double dbl3 = 10.00001;
    // printf("test");

    // s1 = ft_strnew(4);
    s1 = "yOlo";
    s2 = "Fabiooooo";
    s3 = 'A';

    setlocale(LC_ALL, "en_US.UTF-8");
    // printf("R: %d\n", printf("{%4.15S}", L"ÊM-M-^QÊM-^X‰∏M-ÂM-^O™M-^L´„M-M-^B"));
    // printf("R: %d\n", printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
    // ft_putnbr(printf("%lc", 1045));
    // ft_putnbr(ft_printf("%lc", 1045));
    // printf("%ls\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
    // ft_printf("%ls\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
    // printf("F: %d\n", ft_printf("{%4.15ls}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
    // printf("R: %d\n", printf("{%4.15ls}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
    // wchar_t *yolo = L"我是一只猫。";
    // wchar_t *yolo = L"ÊØ";
    // wchar_t *yolo2 = L"Ø";
    // wchar_t *yolo3 = L"Â";
    // wchar_t *yolo4 = L"Á";
    // wchar_t *yolo5 = L"´";
    // printf("R: %d\n", printf("%ls\n", yolo));
    // printf("F: %d\n", ft_printf("%ls\n", yolo));
    // printf("R: %d\n", printf("%ls\n", yolo2));
    // printf("F: %d\n", ft_printf("%ls\n", yolo2));
    // printf("R: %d\n", printf("%ls\n", yolo3));
    // printf("F: %d\n", ft_printf("%ls\n", yolo3));
    // printf("R: %d\n", printf("%ls\n", yolo4));
    // printf("F: %d\n", ft_printf("%ls\n", yolo4));
    // printf("R: %d\n", printf("R%ls\n", yolo5));
    // printf("F: %d\n", ft_printf("F%ls\n", yolo5));
    printf("R%d\n", printf("%8C et coco\n", 3250));
    printf("F%d\n", ft_printf("%8C et coco\n", 3250));

    return (0);  
}