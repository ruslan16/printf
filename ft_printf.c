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
				else if(format[i] == 'x')
				{
					x = va_arg(ap, int);
					ft_hexadecimal(x);
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
	ft_printf("%x \n " , 2147483648);
	printf("\n%X \n", -1);
	return (0);
}
