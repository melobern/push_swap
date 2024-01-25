/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:16:26 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/25 11:56:58 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nodes_list	*pile_a;

	//	t_nodes_list	*pile_b;
	ft_check_arg(ac, av);
	ft_putendl_fd("PROUT PROUT ! ARGS OK ! PROUT PROUT !", 1);
	pile_a = NULL;
	//	pile_b = NULL;
	fill_pile(&pile_a, av + 1);
	if (!pile_sorted(&pile_a))
	{
		if (pile_len(&pile_a) == 2)
			ft_putendl_fd(sa(&pile_a), 1);
	}
		else if (pile_len(&pile_a) == 3)
			sort_three(&pile_a);
	/*
		else if (pile_len(pile_a) == 3)
			push_swap(&pile_a, &pile_b);
	}
	*/
	show_pile(&pile_a);
	free_pile(&pile_a);
	return (0);
}
