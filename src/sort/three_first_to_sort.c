/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_first_to_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:44:08 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/01 14:15:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_after_first(t_nodes_list **pile_a)
{
	t_nodes_list	*tmp;

	if (!(*pile_a))
		return (0);
	tmp = *pile_a->next;
	return (pile_sorted(tmp));
}


void	first_sort(t_nodes_list pile_a, size_t len)
{
	t_nodes_list	*one;
	size_t		place;

	if (!(*pile_a))
		return ;
	one = *pile_a;
	if (is_top(one))
		ft_putendl_fd(ra(pile_a), 1);
	else if (len > 0)
	{
		place = one->pos;
		if (place < (len / 2))
		{
			while (place > 0)
			// pas possible,, faut push into b.....	
		}

	}
}

int	sorted_after_three_first(t_nodes_list **pile_a)
{
	t_nodes_list	*tmp;

	if (!(*pile_a))
		return (0);
	tmp = *pile_a->next->next;
	return (pile_sorted(tmp));
}

int	three_first_sort(t_nodes_list **pile_a, size_ten len)
{
	t_nodes_list	*one;
	t_nodes_list	*two;
	t_nodes_list	*three;

	if (!(*pile_a))
		return (0);
	one = *pile_a
	two = (*pile_a)->next;
	three = (*pile_a)->next->next;
	if (is_top_three(one) && is_top_three(two) && is_top_three(three))
	{
		ft_putendl_fd(ra(pile_a), 1);
		ft_putendl_fd(ra(pile_a), 1);
		ft_putendl_fd(ra(pile_a), 1);
		sort_three_last(pile_a);
	}
}
