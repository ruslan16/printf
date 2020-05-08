/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:54:23 by etristan          #+#    #+#             */
/*   Updated: 2020/05/08 23:02:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "s_prft.h"
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <sys/types.h>
# include <inttypes.h>

void	ft_print_num(intmax_t n);
int		ft_int(intmax_t n);
int		ft_long_int(intmax_t n);
int		ft_unsigned_int(intmax_t n);
int		ft_printf(const char *format, ...);

void	ft_hex_conv(intmax_t decimal);
void	ft_hex_low_conv(intmax_t decimal);
void	ft_oct_conv(intmax_t decimal);
int		ft_hexadecimal_low(intmax_t n);
int		ft_hexadecimal(intmax_t n);
int		ft_octal(intmax_t n);
int		ft_sizeofnum(intmax_t num);
void	ft_print_memory(unsigned long addr);

char*	ft_parsing(char *str);
int		ft_search_char(char *str, char c);
char*	ft_str_cut(char *str, int len);

void	ft_freelst(t_prft *list);
t_prft	*new_el(char letter, char *line);
t_prft	*add_el(char letter, t_prft *head, char *line);

#endif
