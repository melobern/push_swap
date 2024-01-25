/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:26:28 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/25 13:48:56 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rra(t_nodes_list **pile_a)
{

	t_nodes_list	*tmp;

	tmp = *pile_a;
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->prev != NULL)
	{
		ft_swap(&(tmp->value), &(tmp->prev->value));
		tmp = tmp->prev;
	}
	return ("rra");
}



/*
char	*rrb(t_nodes_list **pile_b);

char	*rrr(t_nodes_list **pile_a, t_nodes_list **pile_b);
*/
/*
rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
rrr : rra et rrb en même temps.
*/
