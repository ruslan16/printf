#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int     ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int x;
    char *str;

    i = 0;
    va_start(ap, format);
    if (ft_strchr(format, '%'))
    {
        while (format[i] != '\0')
        {
            if (format[i] == '%')
            {
                if (format[++i] == '%')
                {
                    ft_putchar('%');
                    i++;
                }

                if (format[i] == 'd')
                {
                    x = va_arg (ap, int);
                    ft_putnbr(x);
                }
                else if (format[i] == 's')
                {
                    str = va_arg (ap, char*);
                    ft_putstr(str);
                }
            }
            if (format[i] == '\n')
                ft_putchar('\n');
            i++;
        }
    }
    else
        ft_putstr(format);
    va_end (ap);
    return (0);
}

int     main ()
{
    ft_printf("fdsfdsf %d \n %s \n " , 213, "fsdfs");
    printf("fsd %% \n");
    return (0);
}