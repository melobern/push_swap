/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:58:09 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 09:34:21 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	search_min(t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	size_t			min;

	tmp = *pile;
	min = tmp->pos;
	while (tmp->next != NULL)
	{
		if (min > tmp->next->pos)
			min = tmp->next->pos;
		tmp = tmp->next;
	}
	return (min);
}
