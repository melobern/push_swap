/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PROUT_PROUT.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:20:18 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/25 11:21:22 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
