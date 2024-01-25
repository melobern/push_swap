/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:55:19 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/25 10:40:35 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FREE PILE A REVOIR :
// PEUT_ETRE MIEUX SI FREE DANS LE BON SENS ET PAS A PARTIR DE LA FIN ?
// A VOIR !
void	free_pile(t_nodes_list **li)
{
	t_nodes_list	*tmp;

	while ((*li)->prev != NULL)
	{
		tmp = (*li)->prev;
		free(*li);
		(*li) = tmp;
	}
	free(*li);
	*li = NULL;
}

int	pile_sorted(t_nodes_list **pile)
{
	t_nodes_list	*start;

	start = *pile;
	while ((*pile)->next != NULL)
	{
		if ((*pile)->value > (*pile)->next->value)
			return (0);
		*pile = (*pile)->next;
	}
	*pile = start;
	return (1);
}

size_t	pile_len(t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	size_t			len;

	len = 1;
	tmp = *pile;
	while (tmp->next != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_nodes_list	*add_num(int number, int index, t_nodes_list *prev_l)
{
	t_nodes_list	*new;

	new = (t_nodes_list *)malloc(sizeof(t_nodes_list));
	if (!new)
		return (NULL);
	new->value = number;
	new->index = index;
	new->next = NULL;
	if (prev_l)
		new->prev = prev_l;
	else
		new->prev = NULL;
	return (new);
}

void	fill_pile(t_nodes_list **pile, char **av)
{
	t_nodes_list	*start;
	int				x;
	int				there_is_malloc;
	char	spaces[7];


	x = 0;
	there_is_malloc = 0;
	if (!av[1])
	{
		ft_fill_spaces(spaces);
		av = ft_split_set(av[0], spaces);
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

void	show_pile(t_nodes_list **pile)
{
	printf("%i\n", (*pile)->value);
	while ((*pile)->next)
	{
		(*pile) = (*pile)->next;
		printf("%i\n", (*pile)->value);
	}
	ft_putendl_fd("PROUT PROUT ! THIS WAS THE PILE A ! CLAP ! CLAP !", 1);
}
