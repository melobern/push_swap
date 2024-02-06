/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:16:26 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/06 14:51:44 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	down_or_up(size_t pos, t_nodes_list **pile_b)
{
	t_nodes_list *b;
	int				up;
	int				down;

	if (!(*pile_b) || pos)
		return (-1);
	up = 0;
	down = 0;
	b = *pile_b;
	while (b->next && pos < b->next->pos)
	{
		down++;
		b = b->next;
	}
	b = *pile_b;
	while (b->next && pos > b->next->pos)
	{
		up++;
		b = b->next;
	}
	if (up > down)
		return (1);
	return (0);
}

void	back_into_a(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	size_t	pos_a;
	size_t	pos_b;
	int				up;

	if (!(*pile_b))
		return ;
	while (*pile_b)
	{
		pos_a = (*pile_a)->pos;
		pos_b = (*pile_b)->pos;
		up = down_or_up(pos_b, pile_b);
		while ((*pile_b)->pos != pos_a - 1)
		{
			if (up == 1)
				ft_putendl_fd(rb(pile_b), 1);
			else
				ft_putendl_fd(rrb(pile_b), 1);
		}
		ft_putendl_fd(pa(pile_a, pile_b), 1);
	}
}

void	push_swap(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	push_into_b(pile_a, pile_b);
	if (!pile_sorted(pile_a))
		sort_three(pile_a);
	if (*pile_b)
		back_into_a(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_nodes_list	*pile_a;
	t_nodes_list	*pile_b;
	size_t			pile_a_len;

	ft_check_arg(ac, av);
	pile_a = NULL;
	pile_b = NULL;
	pile_a_len = fill_pile(&pile_a, av + 1);
	if (!pile_sorted(&pile_a))
	{
		if (pile_a_len == 2)
			ft_putendl_fd(sa(&pile_a), 1);
		else if (pile_a_len == 3)
			sort_three(&pile_a);
		else
			push_swap(&pile_a, &pile_b);
	}
	/*
	// CRAPPY TESTS		////////////////////
	ft_putendl_fd("PILE A !", 1); ////
	show_pile(&pile_a);           ////
	ft_putendl_fd("PILE B !", 1); ////
	show_pile(&pile_b);           ////
	// CRAPPY TESTS		////////////////////
	*/
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}
