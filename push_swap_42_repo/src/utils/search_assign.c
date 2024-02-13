/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_assign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:07:47 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/13 11:40:20 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	dec_to_bin(size_t num)
{
	size_t	bin_num;
	size_t	place;

	bin_num = 0;
	place = 1;
	while (num)
	{
		bin_num += (num % 2) * place;
		num = num / 2;
		place = place * 10;
	}
	return (bin_num);
}

void	assign_nodes(t_nodes_list **pile, size_t len)
{
	size_t			bigger_nums;
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
		if (bigger_nums == 0)
			num->top_one = 1;
		num->pos = len - (bigger_nums + 1);
		//Etrangement, ne pas ajouter 1 pour que le pos minimum soit a 0 rend le tri de 5 plus long, mais l'ajouter double le temps pour 100 et 500 
		num->bin_num = dec_to_bin(num->pos);
		num = num->next;
	}
}

size_t	search_min(t_nodes_list **pile)
{
	t_nodes_list	*tmp;
	size_t			min;

	tmp = *pile;
	min = tmp->pos;
	while (tmp->next != NULL)
	{
		if (min > tmp->next->pos)
			min = tmp->next->pos;
		tmp = tmp->next;
	}
	return (min);
}
