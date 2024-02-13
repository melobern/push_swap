/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:24:24 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 09:32:47 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_nodes_list **pile)
{
	int	one;
	int	two;
	int	three;

	one = (*pile)->value;
	two = (*pile)->next->value;
	three = (*pile)->next->next->value;
	if ((one > two && one < three))
		ft_putendl_fd(sa(pile), 1);
	else if ((one > two && two > three))
	{
		ft_putendl_fd(sa(pile), 1);
		ft_putendl_fd(rra(pile), 1);
	}
	else if ((one > two && one > three))
		ft_putendl_fd(ra(pile), 1);
	else if ((two > one && two > three))
	{
		ft_putendl_fd(rra(pile), 1);
		if (one < three)
			ft_putendl_fd(sa(pile), 1);
	}
}

void	rev_sort(t_nodes_list **pile)
{
	size_t	direction;

	if (!(*pile))
		return ;
	direction = down_or_up((*pile)->pos, pile);
	while (!pile_rev_sorted(pile))
		roll_b(direction, pile);
}
