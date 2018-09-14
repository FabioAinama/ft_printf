#include "includes/ft_printf.h"
// #include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// int    main()
// {
//     char *s1;
//     char *s2;
//     char s3;
//     char *s4;
//     int i;
//     unsigned int ui = 1284;
//     double dbl = 42.1325437;
//     double dbl2 = 49.999999999995;
//     double dbl3 = 10.00001;
//     // printf("test");

//     // s1 = ft_strnew(4);
//     s1 = "yOlo";
//     s2 = "Fabiooooo";
//     s3 = 'A';

//     setlocale(LC_ALL, "en_US.UTF-8");
//     // printf("R: %d\n", printf("{%4.15S}", L"ÊM-M-^QÊM-^X‰∏M-ÂM-^O™M-^L´„M-M-^B"));
//     // printf("R: %d\n", printf("%.4S", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
//     // ft_putnbr(printf("%lc", 1045));
//     // ft_putnbr(ft_printf("%lc", 1045));
//     // printf("%ls\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//     // ft_printf("%ls\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
//     // printf("F: %d\n", ft_printf("{%4.15ls}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
//     // printf("R: %d\n", printf("{%4.15ls}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
//     // wchar_t *yolo = L"我是一只猫。";
//     // wchar_t *yolo = L"ÊØ";
//     // wchar_t *yolo2 = L"Ø";
//     // wchar_t *yolo3 = L"Â";
//     // wchar_t *yolo4 = L"Á";
//     // wchar_t *yolo5 = L"´";
//     // printf("R: %d\n", printf("%ls\n", yolo));
//     // printf("F: %d\n", ft_printf("%ls\n", yolo));
//     // printf("R: %d\n", printf("%ls\n", yolo2));
//     // printf("F: %d\n", ft_printf("%ls\n", yolo2));
//     // printf("R: %d\n", printf("%ls\n", yolo3));
//     // printf("F: %d\n", ft_printf("%ls\n", yolo3));
//     // printf("R: %d\n", printf("%ls\n", yolo4));
//     // printf("F: %d\n", ft_printf("%ls\n", yolo4));
//     // printf("R: %d\n", printf("R%ls\n", yolo5));
//     // printf("F: %d\n", ft_printf("F%ls\n", yolo5));
//     // printf("R%d\n", printf("%8C et coco\n", 3250));
//     // printf("F%d\n", ft_printf("%8C et coco\n", 3250));
//     printf("R%d\n", printf("%.3s\n", 0));
//     printf("F%d\n", ft_printf("%.3s\n", 0));
//     // printf("R%d\n", printf("%s\n", 0));
//     // printf("F%d\n", ft_printf("%s\n", 0));

//     return (0);  
// }

int main(void)
{
//   ft_printf("\n");
//   ft_printf("%%\n");
//   ft_printf("%d\n", 42);
//   ft_printf("%d%d\n", 42, 41);
//   ft_printf("%d%d%d\n", 42, 43, 44);
//   ft_printf("%ld\n", 2147483647);
//   ft_printf("%lld\n", 9223372036854775807);
//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);
//   ft_printf("%p\n", &ft_printf);
//   ft_printf("%20.15d\n", 54321);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   ft_printf("%hhd\n", 0);
//   ft_printf("%jd\n", 9223372036854775807);
//   ft_printf("%zd\n", 4294967295);
//   ft_printf("%\n");
//   ft_printf("%U\n", 4294967295);
//   ft_printf("%u\n", 4294967295);
//   ft_printf("%o\n", 40);
//   ft_printf("%%#08x\n", 42);
//   ft_printf("%x\n", 1000);
//   ft_printf("%#X\n", 1000);
    printf("R: %d\n", printf("%4.11s\n", "42 is the answer"));
    printf("F: %d\n", ft_printf("%4.11s\n", "42 is the answer"));
//   ft_printf("%S\n", L"ݗݜशব");
//   ft_printf("%s%s\n", "test", "test");
//   ft_printf("%s%s%s\n", "test", "test", "test");
//   ft_printf("%C\n", 15000);
//   while (1);
  return (0);
}