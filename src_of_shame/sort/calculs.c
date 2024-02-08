/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:59:29 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/07 18:13:56 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

size_t	near(t_nodes_list *src, t_nodes_list **dest)
{
	t_nodes_list	*s;
	t_nodes_list	*d;
	size_t nearest;
	size_t diff;
	size_t next_diff;

	if (!src || !(*dest))
		return (0);
	s = src;
	d = *dest;
	diff = 4300000000;
	nearest = d->pos;
	while (d)
	{
		next_diff = abs_diff(s->pos, d->pos);
		if (diff > next_diff)
		{
			diff = next_diff;
			nearest = d->pos;
		}
		d = d->next;
	}
	return (nearest);
}

size_t	calcul_pos_b(t_nodes_list *pile_a, t_nodes_list **pile_b)
{
	t_nodes_list	*b;
	size_t nearest;
	size_t			position;

	if (!(pile_a) || !(*pile_b))
		return (0);
	position = 0;
	b = *pile_b;
	nearest = near(pile_a, pile_b);
	if (b->pos == nearest && pile_a->pos < b->pos)
		position++;
	while (b->next && b->pos != nearest)
	{
		position++;
		b = b->next;
		if (b->pos == nearest && pile_a->pos < b->pos)
			position++;
	}
	return (position);
}

size_t	calcul_pos_a(t_nodes_list *pile_b, t_nodes_list **pile_a)
{
	t_nodes_list	*a;
	size_t nearest;
	size_t			position;

	if (!(*pile_a) || !(pile_b))
		return (0);
	position = 0;
	a = *pile_a;
	nearest = near(pile_b, pile_a);
	if (a->pos == nearest && pile_b->pos > a->pos)
		position++;
	while (a->next && a->pos != nearest)
	{
		position++;
		a = a->next;
		if (a->pos == nearest && pile_b->pos > a->pos)
			position++;
	}
	return (position);
}

size_t	search_cheaper_a(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	t_nodes_list	*tmp;
	size_t			b_len;
	size_t			cheaper;
	size_t			extra_cost;

	tmp = *b;
	extra_cost = 0;
	cheaper = calcul_pos_a(*b, a);
	b_len = pile_len(b);
	while (tmp)
	{
		tmp->cost = calcul_pos_a(*b, a);
		if (tmp->cost > (len / 2))
			tmp->cost = len - tmp->cost;
		if (extra_cost > b_len / 2)
			extra_cost = len - extra_cost;
		tmp->cost += extra_cost;
		if (tmp->cost < cheaper)
			cheaper = tmp->cost;
		extra_cost++;
		tmp = tmp->next;
	}
	return (cheaper);
}
/*
void	search_cheaper(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	t_nodes_list	*first;
	t_nodes_list	*sec;

	first = *a;
	sec = (*a)->next;
	first->cost = calcul_pos(*a, b);
	sec->cost = calcul_pos(sec, b) + 1;
	if (first->cost >= (len / 2))
		first->cost = len - first->cost;
	if (sec->cost >= (len / 2))
		sec->cost = len + 1 - sec->cost;
}
*/
