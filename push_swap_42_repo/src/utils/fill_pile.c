/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:48:14 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/12 15:29:49 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_nodes_list	*add_num(int number, t_nodes_list *prev_l)
{
	t_nodes_list	*new;

	new = (t_nodes_list *)malloc(sizeof(t_nodes_list));
	if (!new)
		return (NULL);
	new->value = number;
	new->pos = 0;
	new->up = 0;
	new->down = 0;
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
		exit(EXIT_FAILURE);
	return (args);
}

static void	malloc_error_free_all(t_nodes_list **pile, bool mal, char **tab)
{
	free_pile(pile);
	if (mal)
		ft_free_tab(tab);
	malloc_error();
}

static void	add_node(t_nodes_list ***pile, bool mal, char **av, size_t len)
{
	(**pile)->next = add_num(ft_atoi(av[len]), **pile);
	if ((**pile)->next == NULL)
		malloc_error_free_all(*pile, mal, av);
	(**pile)->next->prev = **pile;
	**pile = (**pile)->next;
	(**pile)->next = NULL;
}

size_t	fill_pile(t_nodes_list **pile, char **av)
{
	t_nodes_list	*start;
	size_t			len;
	bool			there_is_malloc;

	len = 0;
	there_is_malloc = 0;
	if (!av[1])
	{
		av = fill_one_arg(av[0]);
		there_is_malloc = 1;
	}
	*pile = add_num(ft_atoi(av[0]), 0);
	if (!*pile)
		malloc_error_free_all(pile, there_is_malloc, av);
	start = *pile;
	while (av[++len])
		add_node(&pile, there_is_malloc, av, len);
	if (there_is_malloc)
		ft_free_tab(av);
	*pile = start;
	assign_nodes(pile, len);
	return (len);
}
