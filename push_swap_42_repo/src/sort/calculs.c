/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:59:29 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/12 15:58:40 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_first_pile(size_t pos, t_nodes_list **pile, size_t *up, size_t *down)
{
	t_nodes_list	*tmp;

	if (!(*pile) || pos)
		return ;
	tmp = *pile;
	*up = 0;
	*down = 0;
	while (tmp->next && pos != tmp->pos)
	{
		++(*up);
		tmp = tmp->next;
	}
	while (tmp->next)
	{
		++(*down);
		tmp = tmp->next;
	}
}

size_t	near(t_nodes_list *pile_a, t_nodes_list **pile_b)
{
	t_nodes_list	*a;
	t_nodes_list	*b;
	size_t			nearest;
	size_t			diff;
	size_t			next_diff;

	if (!pile_a || !(*pile_b))
		return (0);
	a = pile_a;
	b = *pile_b;
	diff = 4300000000;
	nearest = b->pos;
	while (b)
	{
		next_diff = abs_diff(a->pos, b->pos);
		if (diff > next_diff)
		{
			diff = next_diff;
			nearest = b->pos;
		}
		b = b->next;
	}
	return (nearest);
}

size_t	calcul_pos(t_nodes_list *pile_a, t_nodes_list **pile_b)
{
	t_nodes_list	*b;
	size_t			nearest;
	size_t			position;

	if (!(pile_a) || !(*pile_b))
		return (0);
	position = 0;
	b = *pile_b;
	nearest = near(pile_a, pile_b);
	if (b->pos == nearest && pile_a->value < b->value)
		position++;
	while (b->next && b->pos != nearest)
	{
		position++;
		b = b->next;
		if (b->pos == nearest && pile_a->value < b->value)
			position++;
	}
	return (position);
}

void	calcul_cost(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	t_nodes_list	*first;
	t_nodes_list	*sec;
	

	first = *a;
	sec = (*a)->next;
	place_first_pile(first->pos, a, &(first->up), &(first->down));
	first->cost = calcul_pos(first, b);
	first->up = abs_diff(first->cost, first->up);
	first->down = abs_diff(len - first->cost, first->down);

	place_first_pile(sec->pos, a, &(sec->up), &(sec->down));
	sec->cost = calcul_pos(sec, b);
	sec->up = abs_diff(sec->cost, first->up);
	sec->down = abs_diff(len - sec->cost, first->down);
}
