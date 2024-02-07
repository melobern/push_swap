/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:01:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/07 08:25:35 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	near(t_nodes_list *pile_a, t_nodes_list **pile_b)
{
	t_nodes_list	*a;
	t_nodes_list	*b;
	size_t			nearest;
	size_t			diff;

	if (!pile_a || !(*pile_b))
		return (0);
	a = pile_a;
	b = *pile_b;
	diff = abs_diff(a->pos, b->pos);
	nearest = b->pos;
	while (b)
	{
		if (diff > abs_diff(a->pos, b->pos) && a->value > b->value)
		{
			diff = abs_diff(a->pos, b->pos);
			nearest = b->pos;
		}
		b = b->next;
	}
	return (nearest);
}

static size_t	calcul_pos(t_nodes_list *pile_a, t_nodes_list **pile_b)
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
		/* ajout recent */
		if (b->pos == nearest && pile_a->value < b->value)
		position++;
	}
	// printf("Position de %i est %li\n", pile_a->value, position);
	return (position);
}

static size_t	calcul_cost(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	t_nodes_list	*tmp;
	size_t	a_len;
	size_t	cheaper;
	size_t			extra_cost;

	tmp = *a;
	extra_cost = 0;
	cheaper = calcul_pos(*a, b);
	a_len = pile_len(a);
	while (tmp)
	{
		tmp->cost = calcul_pos(*a, b);
		if (tmp->cost > (len / 2))
			tmp->cost = len - tmp->cost;
		if (extra_cost > a_len / 2)
			extra_cost = len - extra_cost;
		tmp->cost += extra_cost;
		if (tmp->cost < cheaper)
			cheaper = tmp->cost;
		extra_cost++;
		tmp = tmp->next;
	}
	return (cheaper);
}

static void	sync_rotate_a(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	size_t	position;
	size_t	cheaper;
	size_t	a_len;

	a_len = pile_len(a);
	cheaper = calcul_cost(a, b, b_len);
	position = calcul_pos(*a, b);
	while ((*a)->cost != cheaper)
	{
		if (cheaper < a_len / 2 && position < b_len / 2)
		{
			while (position-- && (*a)->cost != cheaper)
				ft_putendl_fd(rr(a, b), 1);
		}
		else if (cheaper < a_len / 2)
				ft_putendl_fd(ra(a), 1);
		else if (cheaper > a_len / 2 && position > b_len / 2)
		{
			while (position-- && (*a)->cost != cheaper)
				ft_putendl_fd(rrr(a, b), 1);
		}
		else if (cheaper > a_len / 2)
			ft_putendl_fd(rra(a), 1);
	}
}

static void	move_position(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	size_t	x;
	size_t	position;
	size_t	p_len;

	sync_rotate_a(a, b, b_len);
	position = calcul_pos(*a, b);
	if (position == 2)
	{
		ft_putendl_fd(pb(b, a), 1);
		calcul_cost(a, b, b_len);
		if ((*a)->cost > (*a)->next->cost)
			ft_putendl_fd(ss(a, b), 1);
		else
			ft_putendl_fd(sb(b), 1);
		return ;
	}
	x = position;
	p_len = b_len;
	while (position > 0 && x > 0 && (b_len > 1 && p_len >= b_len))
	{
		if (position < (b_len - position))
			ft_putendl_fd(rb(b), 1);
		else
		{
			b_len = b_len - position;
			if (b_len == 0)
				b_len++;
			while (b_len--)
				ft_putendl_fd(rrb(b), 1);
		}
		x--;
	}
	ft_putendl_fd(pb(b, a), 1);
	if (position == p_len)
		ft_putendl_fd(rb(b), 1);
}

static void	chose_move(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	b_len;
	int		a;

	a = (*pile_a)->value;
	b_len = pile_len(pile_b);
	if (b_len < 2 || (pile_rev_sorted(pile_b) && (is_min_max(a, pile_b))))
	{
		ft_putendl_fd(pb(pile_b, pile_a), 1);
		if (b_len > 0 && is_min((*pile_b)->value, pile_b))
		{
			if (is_top_three(*pile_a))
				ft_putendl_fd(rr(pile_a, pile_b), 1);
			else
				ft_putendl_fd(rb(pile_b), 1);
		}
	}
	else
		move_position(pile_a, pile_b, b_len);
}

void	push_into_b(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	pos_a;
	size_t	pos_n;

	if (!(*pile_a))
		return ;
	while ((*pile_a)->next->next->next != NULL && !pos_linear(pile_a))
	{
		pos_a = (*pile_a)->pos;
		pos_n = (*pile_a)->next->pos;
		if (is_top_three(*pile_a) && pos_a == pos_n + 1)
			ft_putendl_fd(sa(pile_a), 1);
		else
			chose_move(pile_a, pile_b);
		if (pos_linear(pile_a))
			break ;
	}
}
