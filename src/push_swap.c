/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:16:26 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/30 13:45:05 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	push_into_b(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_nodes_list	*pile_a;
	t_nodes_list	*pile_b;

	ft_check_arg(ac, av);
	pile_a = NULL;
	pile_b = NULL;
	fill_pile(&pile_a, av + 1);
	// TO SUPPRESS IN THE END	////////////////////
	if (pile_a == NULL || pile_a->next == NULL)	////
	{						////
		free_pile(&pile_a);			////
		return (0);				////
	}						////
	// TO SUPPRESS IN THE END	////////////////////
	if (!pile_sorted(&pile_a))
	{
		if (pile_len(&pile_a) == 2)
			ft_putendl_fd(sa(&pile_a), 1);
		else if (pile_len(&pile_a) == 3)
			sort_three(&pile_a);
		else
			push_swap(&pile_a, &pile_b);
	}
	// CRAPPY TESTS		////////////////////
	ft_putendl_fd("PILE A !", 1);		////
	show_pile(&pile_a);			////
	ft_putendl_fd("PILE B !", 1);		////
	show_pile(&pile_b);			////
	// CRAPPY TESTS		////////////////////
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}
