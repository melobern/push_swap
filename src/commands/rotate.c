/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:40:35 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 11:34:25 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	tmp = *pile;
	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	while (tmp->next != NULL)
	{
		ft_swap_node(tmp, tmp->next);
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
}

char	*ra(t_nodes_list **pile_a)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	rotate(pile_a);
	return ("ra");
}

char	*rb(t_nodes_list **pile_b)
{
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return (NULL);
	rotate(pile_b);
	return ("rb");
}

char	*rr(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_a == NULL || *pile_b == NULL)
		return (NULL);
	rotate(pile_a);
	rotate(pile_b);
	return ("rr");
}

/*
ra (rotate a) : Décale vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
rb (rotate b) : Décale vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
rr : ra et rb en même temps.
*/
