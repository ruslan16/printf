#include "../includes/ft_printf.h"

void	print_percent(t_printf *f)
{
	write(1, "%", 1);
	f->n_print++;
}

void	charnull(t_printf *f)
{
	int n;

	n = 0;
	if (f->width > 0)
	{
		n = f->width - 1;
		if (f->minus == 0)
		{
			writespace(n);
			write(1, "", 1);
		}
		else if (f->minus > 0)
		{
			write(1, "", 1);
			writespace(n);
		}
		f->n_print += n + 1;
	}
	else
		f->n_print += write(1, "", 1);
}

void	print_char(t_printf *f, va_list ap)
{
	char c;
	int n;

	n = 0;
	c = (unsigned char)va_arg(ap, int);
	if (c == 0)
	{
		charnull(f);
		return;
	}
	if (f->width > 0)
	{
		n = f->width - 1;
		if (f->minus == 0)
		{
			writespace(n);
			write(1, &c, 1);
		}
		else if (f->minus > 0)
		{
			write(1, &c, 1);
			writespace(n);
		}
	}
	else
		write(1, &c, 1);
	f->n_print += n + 1;
}