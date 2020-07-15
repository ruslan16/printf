#include "../includes/ft_printf.h"

void	zero_struct(t_printf *list)
{
	list->pos = 0;
	list->n_print = 0;
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precis_status = 0;
	list->precision = 0;
	list->modif = 0;
}

void	zero_struct_two(t_printf *list)
{
	list->len = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precis_status = 0;
	list->precision = 0;
	list->modif = 0;
}