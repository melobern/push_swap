/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:07:47 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 09:51:53 by mbernard         ###   ########.fr       */
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
