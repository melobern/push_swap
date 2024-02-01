/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:24:24 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/31 13:49:43 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	t_nodes_list	*one;
	t_nodes_list	*two;
	t_nodes_list	*three;
	t_nodes_list	*four;
	t_nodes_list	*five;

	one = (*pile_a)
	two = (*pile_a)->next;
	three = (*pile_a)->next->next;
	four = (*pile_a)->next->next->next;
	five = (*pile_a)->next->next->next->next;
	if (!(is_top_three(one)) && !(is_top_three(two)))
	{
		if (one < two && three > four)
		{
			ft_putendl_fd(pb(pile_b, pile_a), 1);
			ft_putendl_fd(pb(pile_b, pile_a), 1);
			ft_putendl_fd(ss(pile_a, pile_b), 1);
			sort_three(pile_a);
			ft_putendl_fd(pa(pile_b, pile_a), 1);
			ft_putendl_fd(pa(pile_b, pile_a), 1);
		}
	}
	else if (!(is_top_three()))
	{
		ft_putendl_fd(sa(pile_a), 1);
		ft_putendl_fd(rra(pile_a), 1);
	}
	else if ((one > two && one > three))
		ft_putendl_fd(ra(pile_a), 1);
	else if ((two > one && two > three))
	{
		ft_putendl_fd(rra(pile_a), 1);
		if (one < three)
			ft_putendl_fd(sa(pile_a), 1);
	}
}
