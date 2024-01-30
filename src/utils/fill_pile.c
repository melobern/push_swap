/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:48:14 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/30 16:52:37 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes_list	*add_num(int number, int index, t_nodes_list *prev_l)
{
	t_nodes_list	*new;

	new = (t_nodes_list *)malloc(sizeof(t_nodes_list));
	if (!new)
		return (NULL);
	new->value = number;
	new->index = index;
	new->top_three = 0;
	new->next = NULL;
	if (prev_l)
		new->prev = prev_l;
	else
		new->prev = NULL;
	return (new);
}

static char	**fill_one_arg(char *av)
{
	char	spaces[7];
	char	**args;

	ft_fill_spaces(spaces);
	args = ft_split_set(av, spaces);
	if (!args)
		ft_perror();
	return (args);
}

void	fill_pile(t_nodes_list **pile, char **av)
{
	t_nodes_list	*start;
	int				x;
	int				there_is_malloc;

	x = 0;
	there_is_malloc = 0;
	if (!av[1])
	{
		av = fill_one_arg(av[0]);
		there_is_malloc = 1;
	}
	*pile = add_num(ft_atoi(av[0]), 0, 0);
	start = *pile;
	while (av[++x])
	{
		(*pile)->next = add_num(ft_atoi(av[x]), x, *pile);
		(*pile)->next->prev = *pile;
		*pile = (*pile)->next;
	}
	*pile = start;
	if (there_is_malloc)
		ft_free_tab(av);
}
