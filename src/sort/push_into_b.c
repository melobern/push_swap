/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:01:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/08 15:02:36 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_position(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	size_t	x;
	size_t	position;
	size_t	p_len;

	calcul_cost(a, b, len);
	if ((*a)->cost > (*a)->next->cost && !is_top_three((*a)->next))
	{
		/*if ((*b)->pos < (*b)->next->pos && (*b)->next->next->pos < (*b)->pos)
			ft_putendl_fd(ss(a, b), 1);
		else
			*/
		ft_putendl_fd(sa(a), 1);
	}
	position = calcul_pos(*a, b);
	if (position == 1 && (*b)->next->pos < (*a)->pos)
	{
		ft_putendl_fd(pb(b, a), 1);
		calcul_cost(a, b, len);
		if ((*a)->cost > (*a)->next->cost && !is_top_three((*a)->next))
			ft_putendl_fd(ss(a, b), 1);
		else
			ft_putendl_fd(sb(b), 1);
		return ;
	}
	x = position;
	p_len = len;
	while (position > 0 && x > 0 && (len > 1 && p_len >= len) && position < len)
	{
		if (position < (len - position))
			ft_putendl_fd(rb(b), 1);
		else
		{
			len = len - position;
			if (len == 0)
				len++;
			while (len--)
				ft_putendl_fd(rrb(b), 1);
		}
		x--;
	}
	ft_putendl_fd(pb(b, a), 1);
	/*
	if (position == p_len)
			ft_putendl_fd(rb(b), 1);
			*/
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
			/*
		else
			ft_putendl_fd(rb(pile_b), 1);
			*/
		}
	}
	else
		move_position(pile_a, pile_b, b_len);
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

bool	sorted_if_rotated(t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	size_t			counter;

	tmp = *pile;
	counter = 0;
	while (tmp->next != NULL)
	{
		if (tmp->pos + 1 != tmp->next->pos)
		{
			counter++;
			if (counter > 1)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	rotate_until_sorted(size_t pos, t_nodes_list **a)
{
	t_nodes_list	*tmp;
	size_t			up;
	size_t			down;
	size_t			min;

	tmp = *a;
	up = 0;
	down = 0;
	min = search_min(a);
	while (tmp->next)
	{
		if (pos > tmp->next->pos)
			up++;
		if (pos < tmp->next->pos)
			down++;
		tmp = tmp->next;
	}
	while ((*a)->pos != min)
	{
		if (up >= down)
			ft_putendl_fd(ra(a), 1);
		else
			ft_putendl_fd(rra(a), 1);
	}
}

void	push_into_b(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	pos_a;
	size_t	pos_n;
	t_nodes_list	*two_next;

	if (!(*pile_a))
		return ;
	while ((*pile_a)->next->next->next != NULL && !pos_linear(pile_a))
	{
		if (sorted_if_rotated(pile_a))
			return (rotate_until_sorted((*pile_a)->pos, pile_a));
		pos_a = (*pile_a)->pos;
		pos_n = (*pile_a)->next->pos;
		two_next = (*pile_a)->next; 
		if (!is_top_three(*pile_a) && pos_a == pos_n + 1 && pile_sorted(&two_next))
			ft_putendl_fd(sa(pile_a), 1);
		else if (is_top_three(*pile_a))
			ft_putendl_fd(ra(pile_a), 1);
		/*
			* else if (!is_min_max(next_n, pile_b) && is_min_max(actual_n,
					pile_b))
			ft_putendl_fd(sa(pile_a), 1);
		*/
		else
			chose_move(pile_a, pile_b);
	}
}
