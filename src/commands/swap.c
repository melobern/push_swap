/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:55:45 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/30 18:41:01 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_node(t_nodes_list *a, t_nodes_list *b)
{
	ft_swap(&(a->value), &(b->value));
	ft_swap(&(a->top_three), &(b->top_three));
}

char	*sa(t_nodes_list **pile_a)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	ft_swap_node(*pile_a, (*pile_a)->next);
	return ("sa");
}

char	*sb(t_nodes_list **pile_b)
{
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return (NULL);
	ft_swap_node(*pile_b, (*pile_b)->next);
	return ("sb");
}

char	*ss(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_a == NULL || *pile_b == NULL)
		return (NULL);
	ft_swap_node(*pile_a, (*pile_a)->next);
	ft_swap_node(*pile_b, (*pile_b)->next);
	return ("ss");
}
/*
sa(ft_swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
sb(ft_swap b) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ss : sa et sb en même temps
*/
