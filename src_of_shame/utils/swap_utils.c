/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:49:10 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/07 18:26:00 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_bool(bool *a, bool *b)
{
	bool	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_size_t(size_t *a, size_t *b)
{
	size_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_node(t_nodes_list *a, t_nodes_list *b)
{
	ft_swap(&(a->value), &(b->value));
	ft_swap_size_t(&(a->pos), &(b->pos));
	ft_swap_size_t(&(a->cost), &(b->cost));
	ft_swap_bool(&(a->top_three), &(b->top_three));
}
