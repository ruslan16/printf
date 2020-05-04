#include "ft_printf.h"

int		ft_hexadecimal(intmax_t n)
{
	if (n <= -2147483648 || n >= 2147483648)
	{
		ft_putstr("Error");
		return (0);
	}
	else if (n < 0)
		n = 4294967296 + n;
	ft_hex_conv(n);
	return (1);
}

int		ft_octal(intmax_t n)
{
	if (n <= -2147483648 || n >= 2147483648)
	{
		ft_putstr("Error");
		return (0);
	}
	else if (n < 0)
		n = 4294967296 + n;
	ft_oct_conv(n);
	return (1);
}