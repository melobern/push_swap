/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:30:50 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/07 14:51:06 by mbernard         ###   ########.fr       */
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

bool	is_max(size_t num, t_nodes_list **pile)
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

bool	pos_linear(t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	tmp = *pile;
	while (tmp->next != NULL)
	{
		if (tmp->pos + 1 != tmp->next->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

bool	sorted_if_rotated(t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	size_t			counter;

	tmp = *pile;
	counter = 0;
	while (tmp->next != NULL)
	{
		if (tmp->pos + 1 != tmp->next->pos)
		{
			counter++;
			if (counter > 1)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
