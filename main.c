#include "includes/ft_printf.h"
// #include "libft/libft.h"
#include <stdio.h>
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


    // printf("R: %d\n", printf("%#.x %#.0x\n", 0, 0));
    // printf("R: %d\n", printf("R: %5.0x\n", 42));
    // printf("R: %d\n", printf("R: %2.0x\n", 42));
    // printf("R: %d\n", printf("R: %2.0x\n", 0));
    // printf("R: %d\n", printf("%10s is a string\n", "this"));
    // printf("F: %d\n", ft_printf("%10s is a string\n", "this"));
    // printf("R: %d\n", printf("% Zoo\n"));
    // printf("F: %d\n", ft_printf("% Zoo\n"));
    // printf("R: %d\n", printf("%05d\n", -42));
    // printf("F: %d\n", ft_printf("%05d\n", -42));
    // printf("R: %d\n", printf("% Zoo\n"));
    // printf("F: %d\n", ft_printf("% Zoo\n"));
    // printf("R: %d\n", printf("{%}\n"));
    // printf("R: %d\n", printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
    // printf("F: %d\n", ft_printf("{%30S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
    




    // ft_printf("%%\n");
    // printf("%%\n");
    // ft_printf("%5%", "\n");
    // printf("%5%", "\n");
    // ft_printf("%-5%", "\n");
    // printf("%-5%", "\n");
    // ft_printf("%.0%", "\n");
    // printf("%.0%", "\n");
    // ft_printf("%%", "test", "\n");
    // printf("%%", "test", "\n");
    // ft_printf("%   %", "test", "\n");
    // printf("%   %", "test", "\n");
    // ft_printf("%x\n", 42);
    // printf("%x\n", 42);
    // ft_printf("%X\n", 42);
    // printf("%X\n", 42);
    // ft_printf("%x\n", 0);
    // printf("%x\n", 0);
    // ft_printf("%X\n", 0);
    // printf("%X\n", 0);
    // ft_printf("%x\n", -42);
    // printf("%x\n", -42);
    // ft_printf("%X\n", -42);
    // printf("%X\n", -42);
    // ft_printf("%x\n", 4294967296);
    // printf("%x\n", 4294967296);
    // ft_printf("%X\n", 4294967296);
    // printf("%X\n", 4294967296);
    // ft_printf("%10x\n", 42);
    // printf("%10x\n", 42);
    // ft_printf("%-10x\n", 42);
    // printf("%-10x\n", 42);

    // printf("%x\n", 42);
    // ft_printf("%x\n", 42);
    // printf("R: %d\n", printf("%x\n", 42));
    // printf("F: %d\n", ft_printf("%x\n", 42));
    // printf("R: %d\n", );
    // printf("F: %d\n", );

    // Char
    // printf("Return O: %d\n", printf("Real 6c: %6c\n", 65));
    // printf("Return C: %d\n", ft_printf("Fake 6c: %6c\n", 65));
    // printf("Real -6c: %-6c\n", 65);    
    // ft_printf("Fake -6c: %-6c\n", 65);
    // printf("Real c: %c\n", 500);    
    // ft_printf("Fake c: %c\n", 500);
    // char* l = setlocale(LC_ALL, "");
    // if (l == NULL) {
    //     printf("Locale not set\n");
    // } else {
    //     printf("Locale set to %s\n", l);
    // }
    // setlocale(LC_ALL, "en_US.utf8");
    // printf("Real wc: %lc\n", 945);
    // printf("Real wc: %C\n", 945);
    // printf("Real wc: @ %lc\n", '@');

    // String
    // printf("Return O: %d\n", printf("Real (null).3: %.3s\n", s4));
    // printf("Return C: %d\n", ft_printf("Fake (null).3: %.3s\n", s4));
    // printf("Return O: %d\n", printf("R: %s\n", s4));
    // printf("Return C: %d\n", ft_printf("F: %s\n", s4));
    // printf("Return O: %d\n", printf("R: %s\n", s2));
    // printf("Return C: %d\n", ft_printf("F: %s\n", s2));
    // printf("Return O: %d\n", printf("Real (null): %s\n", s4));
    // printf("Return C: %d\n", ft_printf("Fake (null): %s\n", s4));
    // NOT WORKING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // printf("Real 6s .3s: %6s %% %.3s\n", s1, s2);
    // ft_printf("Fake 6s .3s: %6s %% %.3s\n", s1, s2);
    // printf("Real -6s 8.3s: %-6s %% %8.3s\n", s1, s2);
    // ft_printf("Fake -6s 8.3s: %-6s %% %8.3s\n", s1, s2);
    // printf("Real -6s 2.3s: %-6s %% %2.3s\n", s1, s2);
    // ft_printf("Fake -6s 2.3s: %-6s %% %2.3s\n", s1, s2);

    // Float
    // printf("Real: %f\n", dbl);
    // ft_printf("Fake: %f\n", dbl);
    // printf("Real: %.6f\n", dbl2);
    // ft_printf("Fake: %.6f\n", dbl2);
    // printf("Real 8.3f: %8.3f\n", dbl3);
    // ft_printf("Fake 8.3f: %8.3f\n", dbl3);
    // printf("Real 8f: %8f\n", dbl3);
    // ft_printf("Fake 8f: %8f\n", dbl3);
    // printf("Real 8.0f: %8.0f\n", dbl3);
    // ft_printf("Fake 8.0f: %8.0f\n", dbl3);
    // printf("Real d: %-9.0f\n", 13.5);
    // ft_printf("Fake d: %-9.0f\n", 13.5);

    // Octal
    // printf("Real o: %-9.8o\n", ui);
    // ft_printf("Fake o: %-9.8o\n", ui);
    // printf("Real 1.4o: %-+1.4o\n", 42);      
    // ft_printf("Fake 1.4o: %-+1.4o\n", 42);      
    // printf("Real 4.4o: %-+4.4o\n", 42);      
    // ft_printf("Fake 4.4o: %-+4.4o\n", 42);    
    // printf("Real 4.1o: %-+4.1o\n", 42);      
    // ft_printf("Fake 4.1o: %-+4.1o\n", 42);
    // printf("Real 7.4o: %-7.4o\n", 42);    
    // ft_printf("Fake 7.4o: %-7.4o\n", 42);
    // printf("Real o: %o\n", 2147483649);    
    // ft_printf("Fake o: %o\n", 2147483649);
    // printf("Real o: %o\n", 2147483647);    
    // ft_printf("Fake o: %o\n", 2147483647);
    // NOT WORKING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // printf("Real o: %lo\n", 9223372036854775800);    
    // ft_printf("Fake o: %lo\n", 9223372036854775800);
    // printf("Real o: %lo\n", 42);    
    // ft_printf("Fake o: %lo\n", 42);

    // Decimal 4294967254
    // printf("R: %d\n", printf("Real d: %-+9.6d\n", (int)ui));
    // printf("R: %d\n", ft_printf("Fake d: %-+9.6d\n", (int)ui));
    // printf("R: %d\n", printf("Real d: %-9.6d\n", (int)ui));
    // printf("R: %d\n", ft_printf("Fake d: %-9.6d\n", (int)ui));
    // printf("R: %d\n", printf("Real +6.4d: %+6.4d\n", 42));
    // printf("R: %d\n", ft_printf("Fake +6.4d: %0+6.4d\n", 42));
    // printf("R: %d\n", printf("Real +6.1d: %+6.1d\n", 42));
    // printf("R: %d\n", ft_printf("Fake +6.1d: %0+6.1d\n", 42));
    // printf("R: %d\n", printf("Real 0+8d: %0+8d\n", 42));
    // printf("R: %d\n", ft_printf("Fake 0+8d: %0+8d\n", 42));
    // printf("R: %d\n", printf("Real: %+.4d\n", 42));
    // printf("R: %d\n", ft_printf("Fake: %+.4d\n", 42));
    // printf("R: %d\n", printf("Real +8.4: %+8.4d\n", -42));
    // printf("R: %d\n", ft_printf("Fake +8.4: %+8.4d\n", -42));
    // printf("R: %d\n", printf("Real: %d\n", 4294967254));
    // printf("R: %d\n", ft_printf("Fake: %d\n", 4294967254));
    // printf("R: %d\n", printf("Real: %d\n", 2147483649));
    // printf("R: %d\n", ft_printf("Fake: %d\n", 2147483649));
    // printf("R: %d\n", printf("Real: %d\n", -4294967254));
    // printf("R: %d\n", ft_printf("Fake: %d\n", -4294967254));
    // printf("R: %d\n", printf("Real: %d\n", -2147483649));
    // printf("R: %d\n", ft_printf("Fake: %d\n", -2147483649));

    // %u
    // printf("Real: %u\n", 4294967254);
    // ft_printf("Fake: %u\n", 4294967254);
    // printf("Real: %u\n", 2147483649);
    // ft_printf("Fake: %u\n", 2147483649);
    // printf("Real: %u\n", -4294967254);
    // ft_printf("Fake: %u\n", -4294967254);
    // printf("Real: %u\n", -2147483649);
    // ft_printf("Fake: %u\n", -2147483649);
    // printf("Real: %u\n", -214);
    // ft_printf("Fake: %u\n", -214);
    // printf("Real: %-+18.3u\n", 4294967254);
    // ft_printf("Fake: %-+18.3u\n", 4294967254);
    // printf("Real: %-+18.3u\n", 2147483649);
    // ft_printf("Fake: %-+18.3u\n", 2147483649);
    // printf("Real: %-+18.3u\n", -4294967254);
    // ft_printf("Fake: %-+18.3u\n", -4294967254);
    // printf("Real: %-+18.3u\n", -2147483649);
    // ft_printf("Fake: %-+18.3u\n", -2147483649);
    // printf("Real: %-+18.3u\n", -214);
    // ft_printf("Fake: %-+18.3u\n", -214);

    // %lu
    // printf("Real: %lu\n", -4294967254);
    // ft_printf("Fake: %lu\n", -4294967254);
    // printf("Real: %lu\n", -2147483649);
    // ft_printf("Fake: %lu\n", -2147483649);
    // printf("Real %%llu: %llu\n", 18446744073709551615);
    // ft_printf("Fake %%llu: %llu\n", 18446744073709551615);
    
    // %ld
    // printf("Real %%ld: %+8.3ld\n", 4294967254);
    // ft_printf("Fake %%ld: %+8.3ld\n", 4294967254);
    // printf("Real %%ld: %ld\n", 4294967254);
    // ft_printf("Fake %%ld: %ld\n", 4294967254);
    // printf("Real %%ld: %ld\n", 2147483649);
    // ft_printf("Fake %%ld: %ld\n", 2147483649);
    // printf("Real %%ld: %ld\n", -4294967254);
    // ft_printf("Fake %%ld: %ld\n", -4294967254);
    // printf("Real %%ld: %ld\n", -2147483649);
    // ft_printf("Fake %%ld: %ld\n", -2147483649);
    // printf("Real %%ld: %ld\n", 9223372036854775807);
    // ft_printf("Fake %%ld: %ld\n", 9223372036854775807);
    // printf("Real %%ld: %ld\n", 9223372036854775800);
    // ft_printf("Fake %%ld: %ld\n", 9223372036854775800);
    

    // %lld
    // printf("Real %%lld: %+8.3ld\n", 4294967254);
    // ft_printf("Fake %%lld: %+8.3ld\n", 4294967254);
    // printf("Real %%lld: %lld\n", 4294967254);
    // ft_printf("Fake %%lld: %lld\n", 4294967254);
    // printf("Real %%lld: %lld\n", 2147483649);
    // ft_printf("Fake %%lld: %lld\n", 2147483649);
    // printf("Real %%lld: %lld\n", -4294967254);
    // ft_printf("Fake %%lld: %lld\n", -4294967254);
    // printf("Real %%lld: %lld\n", -2147483649);
    // ft_printf("Fake %%lld: %lld\n", -2147483649);
    // printf("Real %%lld: %lld\n", 9223372036854775807);
    // ft_printf("Fake %%lld: %lld\n", 9223372036854775807);
    // printf("Real %%lld: %lld\n", 9223372036854775800);
    // ft_printf("Fake %%lld: %lld\n", 9223372036854775800);

    // Hexadecimal
    // printf("Real .4x: %.4x\n", 42);
    // ft_printf("Fake .4x: %.4x\n", 42);
    // printf("Real x: %x\n", 0);
    // ft_printf("Fake x: %x\n", 0);
    // printf("Real 5x: %5x\n", -42);
    // ft_printf("Fake 5x: %5x\n", -42);
    // printf("Real -4x: %-4x\n", -42);
    // ft_printf("Fake -4x: %-4x\n", -42);
    // printf("Real x: %x\n", -42);
    // ft_printf("Fake x: %x\n", -42);
    return (0);  
}