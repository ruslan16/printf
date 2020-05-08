/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:00:49 by sirvin            #+#    #+#             */
/*   Updated: 2020/05/08 23:02:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_freelst(t_prft *list)
{
	t_prft	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list;
		free(tmp->str);
		list = tmp->next;
		free(tmp);
	}
}

t_prft	*new_el(char letter, char *line)
{
	t_prft	*new;

	if (!line)
		return (NULL);
	if (!(new = (t_prft *)ft_memalloc(sizeof(t_prft))))
		return (NULL);
	new->name = letter;
	new->str = line;
	new->next = NULL;
	return (new);
}

t_prft	*add_el(char letter, t_prft *head, char *line)
{
	t_prft	*tmp;
	t_prft	*add;

	if (!line)
		return (NULL);
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	add = new_el(letter, line);
	tmp->next = add;
	return (head);
}

