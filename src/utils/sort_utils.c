/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:30:50 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/30 17:57:33 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(int num, t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (!num)
		return (0);
	if (!(*pile))
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (num > tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_max(int num, t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (!num)
		return (0);
	if (!(*pile))
		return (1);
	tmp = *pile;
	while (tmp)
	{
		if (num < tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_top_three(t_nodes_list *pile)
{
	if (pile->top_three == 1)
		return (1);
	return (0);
}

void	search_top_three(t_nodes_list **pile)
{
	int				bigger_nums;
	t_nodes_list	*tmp;
	t_nodes_list	*num;

	tmp = *pile;
	num = *pile;
	while (num)
	{
		tmp = *pile;
		bigger_nums = 0;
		while (tmp)
		{
			if (num->value < tmp->value)
				bigger_nums++;
			tmp = tmp->next;
		}
		if (bigger_nums < 3)
			num->top_three = 1;
		num = num->next;
	}
}
