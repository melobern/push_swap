/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:55:45 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/24 14:03:14 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_nodes_list **pile_a)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	ft_swap(&((*pile_a)->value), &((*pile_a)->next->value));
	return ("sa");
}
/*
char	*sb(t_nodes_list **pile_b)
{
	int	tmp;

	if (*pile_b == NULL || *pile_b->next == NULL)
		return (NULL);
	tmp = pile_b->next;
	while (tmp != NULL)
	{
		pile_b = pile_b->next;
		tmp = pile_b->next;
	}
	ft_swap(tmp, pile_b->next);
	return ("sb");
}

char	*ss(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_a == NULL || *pile_b == NULL)
		return (NULL);
	sa(pile_a);
	sb(pile_b);
	return ("ss");
}
*/
/*
sa(ft_swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun.
sb(ft_swap b) : Intervertit les 2 premiers éléments au sommet de la pile b.
Ne fait rien s’il n’y en a qu’un ou aucun.
ss : sa et sb en même temps
*/
