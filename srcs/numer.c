#include "ft_printf.h"

void	numer(t_printf *f, va_list ap)
{
	int *adress;

	adress = (int*)va_arg(ap, int*);
	*adress = f->n_print;
}