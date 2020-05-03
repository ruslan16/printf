#include "libft/includes/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <inttypes.h>

void	ft_print_num(intmax_t n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_print_num(-n);
	}
	else if (n >= 10)
	{
		ft_print_num(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int		ft_int(intmax_t n)
{
	if (n >= 2147483648 || n <= -2147483648)
	{
		ft_putstr("Error");
		return (0);
	}
	else
		ft_print_num(n);
	return (0);
}

int		ft_long_int(intmax_t n)
{
	if (n >= 9223372036854775807 || n <= -9223372036854775807)
	{
		ft_putstr("Error");
		return (0);
	}
	if (n >= -2147483648 && n <= 2147483648)
	{
		ft_putstr("Error");
		return (0);
	}
	else
		ft_print_num(n);
	return (0);
}

int		ft_unsigned_int(intmax_t n)
{
	if (n >= 2147483648 || n <= -2147483648)
	{
		ft_putstr("Error");
		return (0);
	}
	else if (n >= -2147483647 && n < 0)
	{
		n = 4294967296 + n;
		ft_print_num(n);
		return (0);
	}
	else if (n >= 0 && n <= 2147483647)
		ft_print_num(n);
	return (0);
}

int     ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    intmax_t x;
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
                    x = va_arg(ap, int);
                    ft_int(x);
                }
                else if (format[i] == 's')
                {
                    str = va_arg(ap, char*);
                    ft_putstr(str);
                }
                else if (format[i] == 'u')
				{
                	x = va_arg(ap, int);
                	ft_unsigned_int(x);
				}
                else if(format[i] == 'l')
				{
                	x = va_arg(ap, long);
                	ft_long_int(x);
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
	ft_printf("%u \n " , -2147483647);
	printf("\n%u \n", -2147483647);
    return (0);
}