/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:01:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/07 18:16:14 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	search_cheaper_b(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	t_nodes_list	*tmp;
	size_t			a_len;
	size_t			cheaper;
	size_t			extra_cost;

	tmp = *a;
	extra_cost = 0;
	cheaper = calcul_pos_b(*a, b);
	a_len = pile_len(a);
	while (tmp)
	{
		tmp->cost = calcul_pos_b(*a, b);
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

void	sync_rotate_a(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	size_t	position;
	size_t	cheaper;
	size_t	a_len;

	cheaper = search_cheaper_b(a, b, b_len);
	a_len = pile_len(a) / 2;
	b_len = b_len / 2;
	position = calcul_pos_b(*a, b);
	while ((*a)->cost != cheaper)
	{
		if (cheaper >= a_len && position < b_len)
			ft_putendl_fd(rra(a), 1);
		else if (cheaper < a_len && position > b_len)
			ft_putendl_fd(ra(a), 1);
		else
		{
			while (position-- && cheaper < a_len && (*a)->cost != cheaper)
				ft_putendl_fd(rr(a, b), 1);
			while (position-- && cheaper >= a_len && (*a)->cost != cheaper)
				ft_putendl_fd(rrr(a, b), 1);
		}
		if (cheaper >= a_len)
			position = b_len - 1;
		/*
			* Position sera d'une valeur extreme si il passe dans la derniere boucle
			* Donc redéfinition
			*/
	}
}

void	sync_rotate_b(t_nodes_list **a, t_nodes_list **b, size_t a_len)
{
	size_t	position;
	size_t	cheaper;
	size_t	b_len;

	cheaper = search_cheaper_a(a, b, a_len);
	a_len = a_len / 2;
	b_len = pile_len(b) / 2;
	position = calcul_pos_a(*b, a);
	while ((*b)->cost != cheaper)
	{
		if (cheaper >= b_len && position < a_len)
			ft_putendl_fd(rrb(b), 1);
		else if (cheaper < b_len && position > a_len)
			ft_putendl_fd(rb(b), 1);
		else
		{
			while (position-- && cheaper < b_len && (*b)->cost != cheaper)
				ft_putendl_fd(rr(a, b), 1);
			while (position-- && cheaper >= b_len && (*b)->cost != cheaper)
				ft_putendl_fd(rrr(a, b), 1);
		}
		if (cheaper >= a_len)
			position = a_len - 1;
	}
}

void	sb_or_ss(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	if (!(*a) || !(*b))
		return ;
	search_cheaper_b(a, b, b_len);
	if ((*a)->cost > (*a)->next->cost)
		ft_putendl_fd(ss(a, b), 1);
	else
		ft_putendl_fd(sb(b), 1);
}

void	rotate_b(t_nodes_list **b, size_t position, size_t *b_len)
{
	if (!(*b) || !position || !b_len)
		return ;
	if (position < (*b_len - position))
		ft_putendl_fd(rb(b), 1);
	else
	{
		*b_len = *b_len - position;
		if (*b_len == 0)
			ft_putendl_fd(rrb(b), 1);
		while (*b_len--)
			ft_putendl_fd(rrb(b), 1);
	}
}

void	rb_or_rr(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	if (!(*a) || !(*b))
		return ;
	search_cheaper_b(a, b, b_len);
	if ((*a)->cost > (*a)->next->cost)
		ft_putendl_fd(rr(a, b), 1);
	else
		ft_putendl_fd(rb(b), 1);
}

void	rotate_until_sorted(t_nodes_list **a)
{
	t_nodes_list	*tmp;
	size_t			up;
	size_t			down;

	tmp = *a;
	up = 0;
	down = 0;
	while (tmp->next)
	{
		if (tmp->pos > tmp->next->pos)
			up++;
		if (tmp->pos < tmp->next->pos)
			down++;
	}
	if (up > down)
	{
		while (up--)
		ft_putendl_fd(ra(a), 1);
	}
	else
	{
		while (down--)
		ft_putendl_fd(rra(a), 1);
	}
}

static void	move_position_b(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	size_t	x;
	size_t	position;
	size_t	p_len;
	
	if (sorted_if_rotated(a))
		return (rotate_until_sorted(a));
	sync_rotate_a(a, b, b_len);
	position = calcul_pos_b(*a, b);
	if (position == 1 && (*b)->next->pos < (*a)->pos)
	{
		ft_putendl_fd(pb(b, a), 1);
		return (sb_or_ss(a, b, b_len));
	}
	x = position;
	p_len = b_len;
	while (x > 0 && position < b_len && b_len > 1 && p_len >= b_len)
	{
		rotate_b(b, position, &b_len);
		x--;
	}
	ft_putendl_fd(pb(b, a), 1);
}

void	push_into_b(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	b_len;
	size_t	a;

	if (!(*pile_a))
		return ;
	while ((*pile_a)->next->next->next != NULL && !pos_linear(pile_a))
	{
		a = (*pile_a)->pos;
		b_len = pile_len(pile_b);
		if (b_len < 2 || (pile_rev_sorted(pile_b) && (is_min_max(a, pile_b))))
			ft_putendl_fd(pb(pile_b, pile_a), 1);
		else
			move_position_b(pile_a, pile_b, b_len);
	}
}
