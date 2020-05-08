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
	char			name;
	char			*str;
	struct s_prft	*next;
}					t_prft;

#endif
