/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:01:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/05 13:22:42 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	pos_node(int num, t_nodes_list **pile_b)
{
	t_nodes_list	*b;
	size_t			position;

	if (!num || !(*pile_b))
		return (0);
	position = 0;
	b = *pile_b;
	while (b && num < b->value)
	{
		if (num < b->value)
			position++;
		b = b->next;
	}
//	printf("Position de %i est %li\n", num, position);
	return (position);
}

static void	calcul_cost(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	t_nodes_list	*first;
	t_nodes_list	*sec;

	first = *a;
	sec = (*a)->next;
	first->cost = pos_node(first->value, b);
	sec->cost = pos_node(sec->value, b) + 1;
	if (first->cost > (len / 2))
		first->cost = len - first->cost;
	if (sec->cost > (len / 2))
		sec->cost = len - sec->cost;

}

static void	move_position(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	size_t	x;
	size_t	position;
	size_t	p_len;
	
	calcul_cost(a, b, len);
	if ((*a)->cost > (*a)->next->cost && !is_top_three((*a)->next))
		ft_putendl_fd(sa(a), 1);
	position = pos_node((*a)->value, b);
	if (position > len / 2)
	{
		rev_sort(b);
		position = pos_node((*a)->value, b);
	}
	x = position;
	p_len = len;
	while (position > 0 && x > 0 && (len > 1 && p_len >= len))
	{
//		show_pile(b); ////
		if (position < (len - position))
			ft_putendl_fd(rb(b), 1);
		else
		{
			len = len - position;
			while (len--)
				ft_putendl_fd(rrb(b), 1);
		}
		x--;
	}
	ft_putendl_fd(pb(b, a), 1);
	if (position == p_len)
			ft_putendl_fd(rb(b), 1);
		
//	show_pile(b); ////
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
			ft_putendl_fd(rb(pile_b), 1);
	}
	else
		move_position(pile_a, pile_b, b_len);
}


void	push_into_a(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (!(*pile_b))
		return ;
	while (*pile_b)
		ft_putendl_fd(pa(pile_a, pile_b), 1);
	while (!pile_sorted(pile_a))
		ft_putendl_fd(ra(pile_a), 1);
}

void	push_into_b(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	pos_a;
	size_t	pos_n;
	int	actual_n;
	int	next_n;

	if (!(*pile_a))
		return ;
	while ((*pile_a)->next->next->next != NULL && !pos_linear(pile_a))
	{
		pos_a = (*pile_a)->pos;
		pos_n = (*pile_a)->next->pos;
		actual_n = (*pile_a)->value;
		next_n = (*pile_a)->next->value;
		if (is_top_three(*pile_a) && pos_a == pos_n + 1)
			ft_putendl_fd(sa(pile_a), 1);
		else if (is_top_three(*pile_a))
			ft_putendl_fd(ra(pile_a), 1);
		else if (!is_min_max(next_n, pile_b) && is_min_max(actual_n, pile_b))
			ft_putendl_fd(sa(pile_a), 1);
		else
			chose_move(pile_a, pile_b);
		if (pos_linear(pile_a))
			break ;
	}
}
