/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROUT_PROUT.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:20:18 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/30 10:17:44 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_pile(t_nodes_list **pile)
{
	t_nodes_list	*tmp;

	if (!(*pile))
	{
		ft_putendl_fd("Oh ! It seems there was no pile after all :)", 1);
		return ;
	}
	tmp = *pile;
	printf("%i\n", tmp->value);
	while (tmp->next)
	{
		tmp = tmp->next;
		printf("%i\n", tmp->value);
	}
}
