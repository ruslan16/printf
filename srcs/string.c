#include "../includes/ft_printf.h"

void	strnull(t_printf *f)
{
	while (f->width-- > 0)
		f->n_print += write(1, " ", 1);
}

void	left_string(t_printf *f, char *str, int len)
{
	if (f->precis_status && len > f->precision)
		len = f->precision;
	write(1, str, len);
	f->n_print += len;
	while (f->width > len)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
}

void	right_string(t_printf *f, char *str, int len)
{
	if (f->precis_status && len > f->precision)
		len = f->precision;
	while (f->width > len)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
	write(1, str, len);
	f->n_print += len;
}

void	print_string(t_printf *f, va_list ap)
{
	char *str;
	int i;

	str = (char *)va_arg(ap, char *);
	if (str == NULL)
	{
		if (f->precis_status && f->precision < 6)
		{
			strnull(f);
			return ;
		}
		else
			str = "(null)";
	}
	i = ft_strlen(str);
	if (f->minus != 0)
		left_string(f, str, i);
	else
		right_string(f, str, i);
}