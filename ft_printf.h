/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:54:23 by etristan          #+#    #+#             */
/*   Updated: 2020/05/03 23:09:39 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
int		ft_hexadecimal(intmax_t n);

#endif
