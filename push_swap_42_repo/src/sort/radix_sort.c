/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:48:42 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/13 12:41:32 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	max_bytes_len(t_nodes_list **p)
{
	size_t	max_bytes;
	size_t	max_num;
	t_nodes_list	*tmp;

	max_bytes = 0;
	tmp = *p;
	while (tmp->top_one != 1)
		tmp = tmp->next;
	max_num = tmp->pos;
	while (max_num)
	{
		max_bytes++;
		max_num = max_num / 10;
	}
	return (max_bytes);
}

void	radix_sort(t_nodes_list **a, t_nodes_list **b)
{
	size_t	max_bytes;

	max_bytes = max_bytes_len(a);
	
}
