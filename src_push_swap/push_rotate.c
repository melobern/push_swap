/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:40:35 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/25 14:45:50 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
char	*pa(t_nodes_list **pile_a, t_nodes_list **pile_b);;
char	*pb(t_nodes_list **pile_b, t_nodes_list **pile_b);;
*/

char	*ra(t_nodes_list **pile_a)
{
	t_nodes_list	*tmp;

	tmp = *pile_a;
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		ft_swap(&(tmp->value), &(tmp->next->value));
		tmp = tmp->next;
	}
	return ("ra");
}

char	*rb(t_nodes_list **pile_b)
{
	t_nodes_list	*tmp;

	tmp = *pile_b;
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return (NULL);
	while (tmp->next != NULL)
	{
		ft_swap(&(tmp->value), &(tmp->next->value));
		tmp = tmp->next;
	}
	return ("rb");
}

char	*rr(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_a == NULL || *pile_b == NULL)
		return (NULL);
	ra(pile_a);
	rb(pile_b);
	return ("rr");
}

/*
pa (push a) : Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
pb (push b) : Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.
ra (rotate a) : Décale vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
rb (rotate b) : Décale vers le haut tous les élements de la pile b.
Le premier élément devient le dernier.
rr : ra et rb en même temps.
*/
