/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/23 13:40:02 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nodes_list **a, t_nodes_list **b)
{
	int	tmp;

	tmp = *(a->content);
	*(a->content) = *(b->content);
	*(b->content) = tmp;
}

void	free_pile(t_nodes_list **li)
{
	t_nodes_list	*tmp;

	while (li != NULL)
	{
		tmp = li->next;
		free(li);
		li = tmp;
	}
}

int	pile_sorted(t_nodes_list **li)
{
	while (li->next != NULL)
	{
		if (li->content > li->next->content)
			return (0);
		li = li->next;
	}
	return (1);
}

t_nodes_list	*add_num(int number, int index)
{
	t_nodes_list	*new;

	new = (t_nodes_list *)malloc(sizeof(t_nodes_list));
	if (!new)
		return (NULL);
	*(new->content) = number;
	*(new->index) = index;
	new->next = NULL;
	return (new);
}

void	fill_pile(t_nodes_list **pile, char **av)
{
	t_nodes_list	*tmp;
	int	x;

	x = 0;
	while (av[x])
	{
		tmp = pile;
		pile->next = add_num(ft_atoi(av[x]), x);
		pile = pile->next;
		pile->prev = tmp;
		x++;
	}
}

