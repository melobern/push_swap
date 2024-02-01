/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:30:50 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/01 13:54:26 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(int num, t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (!num)
		return (0);
	if (!(*pile))
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (num > tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_max(int num, t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (!num)
		return (0);
	if (!(*pile))
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (num < tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_top_three(t_nodes_list *pile)
{
	return (pile->top_three == 1);
}

