/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:07:47 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 13:30:11 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_nodes(t_nodes_list **pile, size_t len)
{
	size_t			bigger_nums;
	t_nodes_list	*tmp;
	t_nodes_list	*num;

	tmp = *pile;
	num = *pile;
	while (num)
	{
		tmp = *pile;
		bigger_nums = 0;
		while (tmp)
		{
			if (num->value < tmp->value)
				bigger_nums++;
			tmp = tmp->next;
		}
		if (bigger_nums < 3)
			num->top_three = 1;
		num->pos = len - bigger_nums;
		num = num->next;
	}
}

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
