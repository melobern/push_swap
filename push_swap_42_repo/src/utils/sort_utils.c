/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:30:50 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 14:05:41 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_min(size_t num, t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (!num)
		return (0);
	if (!(*pile))
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (num > tmp->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static bool	is_max(size_t num, t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (!num)
		return (0);
	if (!(*pile))
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (num < tmp->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

bool	is_min_max(size_t num, t_nodes_list **pile)
{
	return (is_min(num, pile) || is_max(num, pile));
}

bool	is_top_three(t_nodes_list *pile)
{
	if (pile->top_three == 1)
		return (1);
	return (0);
}
