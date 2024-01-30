/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:01:31 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/30 19:12:48 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	pos_node(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	t_nodes_list	*tmp;
	size_t			position;

	position = 0;
	if (!(*pile_a) || !(*pile_b))
		return (0);
	tmp = *pile_b;
	while (tmp)
	{
		if ((*pile_a)->value < tmp->value)
			position++;
		tmp = tmp->next;
	}
	return (position);
}

static void	chose_move(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	position;
	size_t	b_len;
	size_t	x;

	position = pos_node(pile_a, pile_b);
	b_len = pile_len(pile_b);
	x = b_len / 2 - 1;
	if (position < 3)
	{
		pb(pile_b, pile_a);
		sort_three_b(pile_b);
	}
	else
	{
		while (x > 0)
		{
			if (position > b_len / 2)
				rrb(pile_b);
			else
				rb(pile_b);
			x--;
		}
		pb(pile_b, pile_a);
	}
}

static void	push_into_a(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (!(*pile_b))
		return ;
	ft_putendl_fd("PILE B SHOWTIME !", 1);
	show_pile(pile_b); ////
	while (*pile_b)
		pa(pile_a, pile_b);
	while (!pile_sorted(pile_a))
		ra(pile_a);
}

void	push_into_b(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (!(*pile_a))
		return ;
	search_top_three(pile_a);
	while ((*pile_a)->next->next->next != NULL)
	{
		if (is_top_three(*pile_a))
			ra(pile_a);
		else if (is_max((*pile_a)->value, pile_b))
			pb(pile_b, pile_a);
		else if (is_min((*pile_a)->value, pile_b))
		{
			ft_putendl_fd(pb(pile_b, pile_a), 1);
			ft_putendl_fd(rb(pile_b), 1);
		}
		else
			chose_move(pile_a, pile_b);
	}
	if (!pile_sorted(pile_a))
		sort_three(pile_a);
	if (pile_rev_sorted(pile_b))
		push_into_a(pile_a, pile_b);
}
