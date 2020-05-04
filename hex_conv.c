#include "ft_printf.h"

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
		remainder = quotient % 16;				//step 1
		if (remainder < 10)
			hexadecimal[j++] = 48 + remainder;	//step 2
		else
			hexadecimal[j++] = 55 + remainder;	//step 3
		quotient = quotient / 16;				//step 4
	}
	i = j;
	while (i >= 0)
		ft_putchar(hexadecimal[i--]);
	ft_putchar('\n');
}
