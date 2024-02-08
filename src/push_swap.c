/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:16:26 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/08 15:20:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	down_or_up(size_t pos, t_nodes_list **pile)
{
	t_nodes_list	*b;
	int				up;
	int				down;

	if (!(*pile) || pos)
		return (-1);
	up = 0;
	down = 0;
	b = *pile;
	while (b->next)
	{
		if (pos > b->next->pos)
			up++;
		if (pos < b->next->pos)
			down++;
		b = b->next;
	}
	if (up > down)
		return (1);
	return (0);
}

void	roll_a(bool down, t_nodes_list **pile_a)
{
	if (down == 1)
		ft_putendl_fd(ra(pile_a), 1);
	else
		ft_putendl_fd(rra(pile_a), 1);
}

void	back_into_a(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	bool	up;
	bool	down;

	if (!(*pile_b))
		return ;
	while (*pile_b)
	{
		if (pile_len(pile_b) == 1)
		{
			down = down_or_up((*pile_a)->pos, pile_a);
			while ((*pile_a)->pos != (*pile_b)->pos + 1)
				roll_a(down, pile_a);
		}
		up = down_or_up((*pile_b)->pos, pile_b);
		while ((*pile_b)->pos != (*pile_a)->pos - 1)
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
	size_t	down;

	push_into_b(pile_a, pile_b);
	if (!pile_sorted(pile_a))
		sort_three(pile_a);
	if (*pile_b)
		back_into_a(pile_a, pile_b);
	down = down_or_up(1, pile_a);
	if (!pile_sorted(pile_a))
	{
		while ((*pile_a)->pos != 1)
			roll_a(down, pile_a);
	}
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
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}
