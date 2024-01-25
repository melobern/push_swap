/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:26:28 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/25 14:34:08 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rra(t_nodes_list **pile_a)
{
	t_nodes_list	*tmp;

	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	tmp = *pile_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->prev != NULL)
	{
		ft_swap(&(tmp->value), &(tmp->prev->value));
		tmp = tmp->prev;
	}
	return ("rra");
}

char	*rrb(t_nodes_list **pile_b)
{
	t_nodes_list	*tmp;

	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return (NULL);
	tmp = *pile_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->prev != NULL)
	{
		ft_swap(&(tmp->value), &(tmp->prev->value));
		tmp = tmp->prev;
	}
	return ("rrb");
}

char	*rrr(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_a == NULL || *pile_b == NULL)
		return (NULL);
	rra(pile_a);
	rrb(pile_b);
	return ("rrr");
}
/*
rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
rrr : rra et rrb en même temps.
*/
