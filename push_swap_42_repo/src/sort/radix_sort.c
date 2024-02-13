/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:48:42 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/13 18:03:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	max_bytes_len(t_nodes_list **p)
{
	size_t			max_bytes;
	size_t			max_num;
	t_nodes_list	*tmp;

	max_bytes = 0;
	tmp = *p;
	while (tmp->top_one != 1)
		tmp = tmp->next;
	max_num = tmp->bin_num;
	while (max_num)
	{
		max_bytes++;
		max_num = max_num / 10;
	}
	return (max_bytes);
}

static void	push_into_a(t_nodes_list **a, t_nodes_list **b)
{
	t_nodes_list	*tmp;

	tmp = *b;
	while (tmp)
	{
		ft_putendl_fd(pa(a, b), 1);
		tmp = *b;
	}
}

void	radix_sort(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	t_nodes_list	*tmp;
	size_t			max_bytes;
	size_t			dec_bytes;
	size_t			a_len;

	max_bytes = max_bytes_len(a);
	dec_bytes = 0;
	while (dec_bytes < max_bytes)
	{
		a_len = 0;
		while (a_len < len)
		{
			tmp = *a;
			if ((tmp->pos >> dec_bytes) & 1)
				ft_putendl_fd(ra(a), 1);
			else
				ft_putendl_fd(pb(b, a), 1);
			a_len++;
		}
		push_into_a(a, b);
		dec_bytes++;
	}
}
