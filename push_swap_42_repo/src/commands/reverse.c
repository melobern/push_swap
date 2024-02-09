/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:26:28 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 13:38:54 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_pile(t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	tmp = *pile;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp->prev != NULL)
	{
		ft_swap_node(tmp, tmp->prev);
		tmp = tmp->prev;
	}
}

char	*rra(t_nodes_list **pile_a)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	reverse_pile(pile_a);
	return ("rra");
}

char	*rrb(t_nodes_list **pile_b)
{
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return (NULL);
	reverse_pile(pile_b);
	return ("rrb");
}

char	*rrr(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_a == NULL || *pile_b == NULL)
		return (NULL);
	reverse_pile(pile_a);
	reverse_pile(pile_b);
	return ("rrr");
}
