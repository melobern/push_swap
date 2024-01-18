/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/18 10:04:36 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *a, t_list *b)
{
	int	tmp;

	tmp = *(a->content);
	*(a->content) = *(b->content);
	*(b->content) = tmp;
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

int	list_is_sorted(t_list *li)
{
	while (li->next != NULL)
	{
		if (li->content > li->next->content)
			return (0);
		li = li->next;
	}
	return (1);
}

t_list	*ft_add_num(int number)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = (int *)malloc(sizeof(int));
	if (!new->content)
		return (NULL);
	*(new->content) = number;
	new->next = NULL;
	return (new);
}
