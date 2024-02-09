/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:55:45 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 13:47:04 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_nodes_list **pile_a)
{
	if (*pile_a == NULL || (*pile_a)->next == NULL)
		return (NULL);
	ft_swap_node(*pile_a, (*pile_a)->next);
	return ("sa");
}

char	*sb(t_nodes_list **pile_b)
{
	if (*pile_b == NULL || (*pile_b)->next == NULL)
		return (NULL);
	ft_swap_node(*pile_b, (*pile_b)->next);
	return ("sb");
}

char	*ss(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	if (*pile_a == NULL || *pile_b == NULL)
		return (NULL);
	ft_swap_node(*pile_a, (*pile_a)->next);
	ft_swap_node(*pile_b, (*pile_b)->next);
	return ("ss");
}
