/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:16:26 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/08 10:17:45 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	down_or_up(size_t pos, t_nodes_list **pile_b)
{
	t_nodes_list	*b;
	size_t			up;
	size_t			down;

	if (!(*pile_b) || pos)
		return (-1);
	up = 0;
	down = 0;
	b = *pile_b;
	while (b->next)
	{
		if (tmp->pos > tmp->next)
			up++;
		if (tmp->pos < tmp->next)
			down++;
	}
	/
	while (b->next && pos < b->next->pos)
	{
	down++;
		b = b->next;
	}
	b = *pile_b;
	while (b->next && pos > b->next->pos)
	{
		up++;
		b = b->next;
	}
	/
	if (up > down)
		return (1);
	return (0);
}
*/

void	sa_or_ss(t_nodes_list **a, t_nodes_list **b, size_t a_len)
{
	if (!(*a) || !(*b))
		return ;
	search_cheaper_a(a, b, a_len);
	if ((*b)->cost > (*b)->next->cost)
		ft_putendl_fd(ss(a, b), 1);
	else
		ft_putendl_fd(sb(b), 1);
}

void	rotate_a(t_nodes_list **a, size_t position, size_t *a_len)
{

	if (!(*a) || !position || !a_len)
		return ;
	if (position < (*a_len - position))
		ft_putendl_fd(ra(a), 1);
	else
	{
		*a_len = *a_len - position;
		if (*a_len == 0)
			ft_putendl_fd(rra(a), 1);
		while (*a_len != 0)
		{
			ft_putendl_fd(rra(a), 1);
			--(*a_len);
		}
	}
}

void	move_position_a(t_nodes_list **a, t_nodes_list **b, size_t a_len)
{
	size_t	x;
	size_t	position;
	size_t	p_len;
	
	sync_rotate_b(a, b, a_len);
	position = calcul_pos_a(*b, a);
	if (position == 1 && (*a)->next->pos > (*b)->pos)
	{
		ft_putendl_fd(pa(a, b), 1);
		return (sa_or_ss(a, b, a_len));
	}
	x = position;
	p_len = a_len;
	while (x > 0 && position < a_len && a_len > 1 && p_len >= a_len)
	{
		rotate_a(a, position, &a_len);
		x--;
	}
	ft_putendl_fd(pa(a, b), 1);
}

void	back_into_a(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	/*
	size_t	pos_a;
	size_t	pos_b;
	int		up;
	*/
	size_t	a_len;
	size_t	b;

	if (!(*pile_b))
		return ;
	/*
		* DONT RUN THE PROGRAM ! PROBLEM HERE !
		* EXPLICATION :
		* LA PILE A CONTIENT 3 CHIFFRES MAIS PLUS FORCEMENT LES PLUS GRANDS
		* DONC, FORCEMENT,
			B NE CONTIENDRA PAS LE CHIFFRE JUSTE AVANT LE 1ER DE A
		* CAR IL Y EN A AURA FORCEMENT UN QUI EST DANS A PARMI LES TROIS DERNIERS !!!
	*/
	while (*pile_b)
	{
		b = (*pile_b)->pos;
		a_len = pile_len(pile_a);
		if (pile_sorted(pile_a) && (is_min_max(b, pile_a)))
			ft_putendl_fd(pa(pile_a, pile_b), 1);
		else
			move_position_a(pile_a, pile_b, a_len);
	/*
		pos_a = (*pile_a)->pos;
		pos_b = (*pile_b)->pos;
		up = down_or_up(pos_b, pile_b);
		while ((*pile_b)->pos != pos_a - 1)
		{
			if (up == 1)
				ft_putendl_fd(rb(pile_b), 1);
			else
				ft_putendl_fd(rrb(pile_b), 1);
		}
	*/
	}
}

void	push_swap(t_nodes_list **pile_a, t_nodes_list **pile_b)
{
	push_into_b(pile_a, pile_b);
	if (!pile_sorted(pile_a))
		sort_three(pile_a);
	if (*pile_b)
		back_into_a(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_nodes_list	*pile_a;
	t_nodes_list	*pile_b;
	size_t			pile_a_len;

	ft_check_arg(ac, av);
	pile_a = NULL;
	pile_b = NULL;
	pile_a_len = fill_pile(&pile_a, av + 1);
	if (!pile_sorted(&pile_a))
	{
		if (pile_a_len == 2)
			ft_putendl_fd(sa(&pile_a), 1);
		else if (pile_a_len == 3)
			sort_three(&pile_a);
		else
			push_swap(&pile_a, &pile_b);
	}
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}
