/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/02 11:53:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_nodes_list **li)
{
	t_nodes_list	*tmp;

	if (*li)
	{
		while ((*li)->next != NULL)
			(*li) = (*li)->next;
		while ((*li)->prev != NULL)
		{
			tmp = (*li)->prev;
			free(*li);
			(*li) = tmp;
		}
		free(*li);
		*li = NULL;
	}
}

int	pile_sorted(t_nodes_list **pile)
{
	t_nodes_list	*start;

	start = *pile;
	while ((*pile)->next != NULL)
	{
		if ((*pile)->value > (*pile)->next->value)
		{
			*pile = start;
			return (0);
		}
		*pile = (*pile)->next;
	}
	*pile = start;
	return (1);
}

int	pos_linear(t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	tmp = *pile;
	while (tmp->next != NULL)
	{
		if (tmp->pos + 1 != tmp->next->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	pile_rev_sorted(t_nodes_list **pile)
{
	t_nodes_list	*start;

	start = *pile;
	while ((*pile)->next != NULL)
	{
		if ((*pile)->value < (*pile)->next->value)
		{
			*pile = start;
			return (0);
		}
		*pile = (*pile)->next;
	}
	*pile = start;
	return (1);
}

size_t	pile_len(t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	size_t			len;

	if (!*pile)
		return (0);
	len = 1;
	tmp = *pile;
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
