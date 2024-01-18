/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/16 15:54:22 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(s_list *a, s_list *b)
{
	int	tmp;

	tmp = *(a->value);
	*(a->value) = *(b->value);
	*(b->value) = tmp;
}

void	ft_free_list(t_list *li)
{
	t_list	*tmp;

	while (li != NULL)
	{
		tmp = li->next;
		free(li);
		li = tmp;
	}
}

int	list_is_sorted(s_list *li)
{
	while (li->next != NULL)
	{
		if (li->value > li->next->value)
			return (0);
		li = li->next;
	}
	return (1);
}

s_list	*ft_add_num(int number)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = (int *)malloc(sizeof(int));
	if (!new->value)
		return (NULL);
	*(new->value) = number;
	new->next = NULL;
	return (new);
}
