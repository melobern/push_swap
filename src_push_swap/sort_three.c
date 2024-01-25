/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:24:24 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/25 14:05:28 by mbernard         ###   ########.fr       */
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
	if ((one > two && one < three)) // 2 1 3
		ft_putendl_fd(sa(pile), 1);
	else if ((one > two && two > three)) // 3 2 1
	{
		ft_putendl_fd(sa(pile), 1);
		ft_putendl_fd(rra(pile), 1);
	}
	else if ((one > two && one > three)) // 3 1 2
		ft_putendl_fd(ra(pile), 1);
	else if ((two > one && two > three)) // 2 3 1 || 1 3 2
	{
		ft_putendl_fd(rra(pile), 1); // 2 3 1 || 1 3 2
		if (one < three) // 1 3 2 (=> 3 1 2)
			ft_putendl_fd(sa(pile), 1);
	}
/*
		1 3 2 OK
		1 2 3 OK
		2 1 3 OK
		2 3 1 OK
		3 1 2 OK
		3 2 1 OK

		3
		1
		2

		3
		2
		1

		2
		3
		1

		2
		1
		3
*/

		
}
