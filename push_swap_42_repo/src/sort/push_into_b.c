/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:01:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/12 16:05:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_position(t_nodes_list **a, t_nodes_list **b, size_t len_b)
{
	size_t	x;
	size_t	position;

	calcul_cost(a, b, len_b);
	if ((*a)->cost > (*a)->next->cost && !is_top_three((*a)->next))
	{	
		if((*a)->next->up > (*a)->next->down)
			ft_putendl_fd(rr(a, b), 1);
		else
			ft_putendl_fd(rrr(a, b), 1);
	}
	//	ft_putendl_fd(sa(a), 1);
	position = calcul_pos(*a, b);
	if (position == 1 && (*b)->next->pos < (*a)->pos)
	{
		ft_putendl_fd(pb(b, a), 1);
		return (ss_or_sb(a, b, len_b));
	}
	x = position;
	while (position > 0 && x > 0 && len_b > 1 && position < len_b)
	{
		rb_or_rrb(b, &len_b, position);
		x--;
	}
	ft_putendl_fd(pb(b, a), 1);
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
		}
	}
	else
		move_position(pile_a, pile_b, b_len);
}

static bool	sorted_if_rotated(t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	t_nodes_list	*last;
	size_t			counter;
	size_t			memento;

	tmp = *pile;
	counter = 0;
	memento = tmp->pos;
	while (tmp->next != NULL)
	{
		if (tmp->pos + 1 != tmp->next->pos)
		{
			counter++;
			if (counter > 1)
				return (0);
		}
		last = tmp;
		tmp = tmp->next;
	}
	return (last->pos == memento + 1);
}

static void	rotate_until_sorted(size_t pos, t_nodes_list **a)
{
	size_t	down;
	size_t	min;

	min = search_min(a);
	down = down_or_up(pos, a);
	while ((*a)->pos != min)
		roll_a(down, a);
}

void	push_into_b(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (!(*pile_a))
		return ;
	while ((*pile_a)->next->next->next != NULL && !pos_linear(pile_a))
	{
		if (sorted_if_rotated(pile_a))
			rotate_until_sorted((*pile_a)->pos, pile_a);
		if (is_top_three(*pile_a))
			ft_putendl_fd(ra(pile_a), 1);
		else
			chose_move(pile_a, pile_b);
	}
}
