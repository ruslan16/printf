#include "../includes/ft_printf.h"

void	left_pointer(t_printf *f, char *pointer, int len)
{
	f->n_print += write(1, "0x", 2);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, pointer, len);
	while (f->width > 0)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
}

void	right_pointer(t_printf *f, char *pointer, int len)
{
	while (f->width > 0)
	{
		f->n_print += write(1, " ", 1);
		f->width--;
	}
	f->n_print += write(1, "0x", 2);
	while (f->precision > 0)
	{
		f->n_print += write(1, "0", 1);
		f->precision--;
	}
	f->n_print += write(1, pointer, len);
}
void	print_pointer(t_printf *f, va_list ap)
{
	char *pointer;
	unsigned long long p;
	int hexlen;

	p = (unsigned long long)va_arg(ap, void *);
	if (p == 0)
	{
		f->n_print += write(1, "(nil)", 5);
		return ;
	}
	pointer = ft_itoa_base(p, 16, LOWER);
	hexlen = ft_strlen(pointer);
	f->precision -= hexlen;
	f->width = f->width - hexlen - 2;
	if (f->minus != 0)
		left_pointer(f, pointer, hexlen);
	else
		right_pointer(f, pointer, hexlen);
	free(pointer);
}