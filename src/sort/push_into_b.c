/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:01:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/02 14:59:44 by mbernard         ###   ########.fr       */
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
	return (position);
}

static void	move_position(t_nodes_list **pile_a, t_nodes_list **pile_b, size_t len)
{
	size_t	x;
	size_t	position;

	position = pos_node((*pile_a)->value, pile_b);
	x = position;
	while (position > 0 && x > 0 && len > 1)
	{
		if (position <= len / 2)
			ft_putendl_fd(rrb(pile_b), 1);
		else
			ft_putendl_fd(rb(pile_b), 1);
		x--;
	}
	ft_putendl_fd(pb(pile_b, pile_a), 1);
}

static void	chose_move(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	b_len;
	int	a;

	a = (*pile_a)->value;
	b_len = pile_len(pile_b);
	if (b_len < 2 || (pile_rev_sorted(pile_b) && (is_min(a, pile_b) || is_max(a, pile_b))))
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
	if (!(*pile_a))
		return ;
	while ((*pile_a)->next->next->next != NULL)
	{
		if (is_top_three(*pile_a))
			ft_putendl_fd(ra(pile_a), 1);
		else
			chose_move(pile_a, pile_b);
		if (pos_linear(pile_a))
			break ;
	}
}
