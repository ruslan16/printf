#include "../includes/ft_printf.h"

void	error(void)
{
	write(1, "", 0);
}

void	writespace(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}

void	writezeros(int n)
{
	while (n > 0)
	{
		write(1, "0", 1);
		n--;
	}
}

int		number_len(intmax_t num, int n)
{
	int nbrlen;

	nbrlen = 0;
	if (num < 0)
	{
		num = -num;
		nbrlen++;
	}
	while (num)
	{
		num = num / n;
		nbrlen++;
	}
	return (nbrlen);
}

char	*ft_itoa_base(uintmax_t value, uintmax_t base, int registr)
{
	char				*s;
	unsigned long long	n;
	int					i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	if (registr == LOWER)
		while (i-- > 0)
		{
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
			n /= base;
		}
	else if (registr == UPPER)
		while (i-- > 0)
		{
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
			n /= base;
		}
	return (s);
}