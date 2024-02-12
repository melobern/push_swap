/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 08:30:54 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/12 15:24:54 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	down_or_up(size_t pos, t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	size_t			up;
	size_t			down;

	if (!(*pile) || pos)
		return (-1);
	up = 0;
	down = 0;
	tmp = *pile;
	while (tmp->next && pos < tmp->next->pos)
	{
		up++;
		tmp = tmp->next;
	}
	while (tmp->next && pos > tmp->next->pos)
	{
		up++;
		tmp = tmp->next;
	}
	while (tmp->next)
	{
		down++;
		tmp = tmp->next;
	}
	return (up > down);
}

void	roll_a(bool direction, t_nodes_list **pile_a)
{
	if (direction == 1)
		ft_putendl_fd(ra(pile_a), 1);
	else
		ft_putendl_fd(rra(pile_a), 1);
}

void	roll_b(bool direction, t_nodes_list **pile_b)
{
	if (direction == 1)
		ft_putendl_fd(rb(pile_b), 1);
	else
		ft_putendl_fd(rrb(pile_b), 1);
}

void	ss_or_sb(t_nodes_list **a, t_nodes_list **b, size_t len)
{
	calcul_cost(a, b, len);
	if ((*a)->cost > (*a)->next->cost && !is_top_three((*a)->next))
		ft_putendl_fd(ss(a, b), 1);
	else
		ft_putendl_fd(sb(b), 1);
}

void	rb_or_rrb(t_nodes_list **b, size_t *len, size_t position)
{
	if (position < (*len - position))
		ft_putendl_fd(rb(b), 1);
	else
	{
		*len = *len - position;
		if (*len == 0)
			ft_putendl_fd(rrb(b), 1);
		while (*len)
		{
			ft_putendl_fd(rrb(b), 1);
			--(*len);
		}
	}
}

/*
* NON FONCTIONNEL, FAIT KO OU CRASHER
void	ra_or_rr(t_nodes_list **a, t_nodes_list **b)
{
	
	t_nodes_list	*tmp;

	tmp = *a;
	while (is_top_three(tmp))
		tmp = tmp->next;
	if (down_or_up(tmp->pos, b))
		ft_putendl_fd(ra(b), 1);
	else
		ft_putendl_fd(rr(a, b), 1);
}
*/
