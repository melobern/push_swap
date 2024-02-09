/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:40:35 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 13:46:02 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_nodes_list **dest, t_nodes_list **src)
{
	t_nodes_list	*tmp;

	tmp = NULL;
	if (*src == NULL)
		return ;
	if ((*src)->next != NULL)
	{
		tmp = (*src)->next;
		(*src)->next->prev = NULL;
	}
	if (*dest != NULL)
	{
		(*src)->next = *dest;
		(*dest)->prev = *src;
		(*dest) = *src;
	}
	else
	{
		(*dest) = *src;
		(*dest)->next = NULL;
	}
	(*src) = tmp;
}

char	*pa(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_b == NULL)
		return (NULL);
	push(pile_a, pile_b);
	return ("pa");
}

char	*pb(t_nodes_list **pile_b, t_nodes_list **pile_a)
{
	if (*pile_a == NULL)
		return (NULL);
	push(pile_b, pile_a);
	return ("pb");
}
