#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int		i;
	intmax_t	x;
	char		*str;

	i = 0;
	va_start(ap, format);
	if (ft_strchr(format, '%'))
	{
		while (format[i] != '\0')
		{
			if (format[i] != '%' && format[i - 1] != '%')
				ft_putchar(format[i]);
			if (format[i] == '%')
			{
				if (format[++i] == '%')
				{
					ft_putchar('%');
					ft_putchar(' ');
					i++;
				}
				if (format[i] == 'd' || format[i] == 'i')
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
				else if(format[i] == 'X')
				{
					x = va_arg(ap, int);
					ft_hexadecimal(x);
				}
				else if(format[i] == 'x')
				{
					x = va_arg(ap, int);
					ft_hexadecimal_low(x);
				}
				else if(format[i] == 'o')
				{
					x = va_arg(ap, int);
					ft_octal(x);
				}
				else if(format[i] == 'c')
				{
					x = va_arg(ap, int);
					ft_putchar(x);
				}
				else if(format[i] == 'p')
				{
					x = va_arg(ap, unsigned long);
					ft_print_memory(x);
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

int	main ()
{
	int b = 5;
	printf("\n%p\n", &b);
	ft_printf("%p\n", &b);
	return (0);
}
