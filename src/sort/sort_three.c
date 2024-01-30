/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:24:24 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/30 15:19:54 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_b(t_nodes_list **pile)
{
	int	one;
	int	two;
	int	three;

	one = (*pile)->value;
	two = (*pile)->next->value;
	three = (*pile)->next->next->value;
	if ((one < two && one > three))
		ft_putendl_fd(sb(pile), 1);
	else if ((one < two && two < three))
	{
		ft_putendl_fd(sb(pile), 1);
		ft_putendl_fd(rrb(pile), 1);
	}
	else if ((one < two && one < three))
		ft_putendl_fd(rb(pile), 1);
	else if ((two < one && two < three))
	{
		ft_putendl_fd(rrb(pile), 1);
		if (one > three)
			ft_putendl_fd(sb(pile), 1);
	}
}

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