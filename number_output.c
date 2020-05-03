#include "ft_printf.h"

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
