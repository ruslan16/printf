#include "ft_printf.h"

void	ft_hex_low_conv(intmax_t decimal)
{
	long	quotient;
	long	remainder;
	int		i;
	int		j;
	char	hexadecimal[100];

	j = 0;
	quotient = decimal;

	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	i = j - 1;
	while (i >= 0)
		ft_putchar(ft_tolower(hexadecimal[i--]));
	ft_putchar('\n');
}

void	ft_hex_conv(intmax_t decimal)
{
	long	quotient;
	long	remainder;
	int		i;
	int		j;
	char	hexadecimal[100];

	j = 0;
	quotient = decimal;

	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;
		else
			hexadecimal[j++] = 55 + remainder;
		quotient = quotient / 16;
	}
	i = j - 1;
	while (i >= 0)
		ft_putchar(hexadecimal[i--]);
	ft_putchar('\n');
}

void	ft_oct_conv(intmax_t decimal)
{
	long	quotient;
	long	remainder;
	int		i;
	int		j;
	char	octal[100];

	j = 0;
	quotient = decimal;

	while (quotient != 0)
	{
		remainder = quotient % 8;
		if (remainder < 10)
			octal[j++] = 48 + remainder;
		else
			octal[j++] = 55 + remainder;
		quotient = quotient / 8;
	}
	i = j - 1;
	while (i >= 0)
		ft_putchar(octal[i--]);
	ft_putchar('\n');
}

int ft_sizeofnum(intmax_t num)
{
	int size = 1;

	while (num > 9)
	{
		num /= 10;
		size++;
	}
	return (size);
}
