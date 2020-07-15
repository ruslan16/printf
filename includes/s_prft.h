/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_prft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etristan <etristan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:44:13 by etristan          #+#    #+#             */
/*   Updated: 2020/05/08 23:03:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PRFT_H
# define S_PRFT_H

typedef struct		s_prft
{
	char			format;
	int				n_print;

	int				pos;
	int				len;
	int				minus;
	int				plus;
	int				zero;
	int				hash;
	int				space;

	int				width;
	int				precis_status;
	int				precision;
	int				modif;
}					t_printf;

#endif
