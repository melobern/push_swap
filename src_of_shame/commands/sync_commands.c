/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:35:21 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/07 16:07:33 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_or_ss(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	calcul_cost_b(a, b, b_len);
	if (!(*a) || !(*b))
		return ;
	if ((*a)->cost > (*a)->next->cost)
		ft_putendl_fd(ss(a, b), 1);
	else
		ft_putendl_fd(sb(b), 1);
}

void	rb_or_rr(t_nodes_list **a, t_nodes_list **b, size_t b_len)
{
	calcul_cost_b(a, b, b_len);
	if (!(*a) || !(*b))
		return ;
	if ((*a)->cost > (*a)->next->cost)
		ft_putendl_fd(rr(a, b), 1);
	else
		ft_putendl_fd(rb(b), 1);
}
