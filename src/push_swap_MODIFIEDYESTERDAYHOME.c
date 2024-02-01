/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:16:26 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/31 13:49:56 by mbernard         ###   ########.fr       */
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
	size_t		pile_a_len;

	ft_check_arg(ac, av);
	pile_a = NULL;
	pile_b = NULL;
	fill_pile(&pile_a, av + 1);
	pile_a_len = pile_len(&pile_a);
	// TO SUPPRESS IN THE END	////////////////////
	if (pile_a == NULL || pile_a->next == NULL)	////
	{						////
		free_pile(&pile_a);			////
		return (0);				////
	}						////
	// TO SUPPRESS IN THE END	////////////////////
	if (!pile_sorted(&pile_a))
	{
		if (pile_a_len == 2)
			ft_putendl_fd(sa(&pile_a), 1);
		else if (pile_a_len == 3)
			sort_three(&pile_a);
		else if (pile_a_len == 5)
			sort_five(&pile_a, &pile_b);
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
