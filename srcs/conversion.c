#include "../includes/ft_printf.h"

void	conversions(char c, t_printf *f, va_list ap)
{
	if (c == 'c')
		print_char(f, ap);
	else if (c == 's')
		print_string(f, ap);
	else if (c == 'p')
		print_pointer(f, ap);
	else if (c == 'd' || c == 'i')
		print_int(f, ap, 0, 0);
	else if (c == 'o')
		print_octal(f, ap);
	else if (c == 'u')
		print_unsigned(f, ap, 0);
	else if (c == 'x' || c == 'X')
		print_hexa(f, ap, c);
	//else if (c == 'f')
		//print_loat(f, ap);
	else if (c == '%')
		print_percent(f);
	//else if (c == 'y')
		//ifcat();
	else if (c == 'b')
		print_binary(f, ap);
}

