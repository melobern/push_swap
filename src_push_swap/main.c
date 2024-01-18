/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:02:42 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/16 15:56:52 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int					value;
	struct s_list	*next;
}						t_list;

void	ft_free_list(t_list *li)
{
	t_list	*tmp;
	while (li != NULL)
	{
		tmp = li->next;
		free(li);
		li = tmp;
	}
}

t_list	*ft_init_list(int x, int y)
{
	t_list	*li;
	t_list	*tmp;

	li = malloc(sizeof(t_list));
	if (!li)
		return (NULL);
	tmp = li;
	while (x <= y)
	{
		tmp->value = x;
		tmp->next = malloc(sizeof(t_list));
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
		x++;
	}
	tmp->next = NULL;
	return (li);
}

void	ft_print_list(t_list *li)
{
	t_list	*tmp;

	tmp = li;
	while (tmp->next != NULL)
	{
		printf("Liste : %d\n", tmp->value);
		tmp = tmp->next;
	}
}

int	main(void)
{
	t_list	*pile_a;
	t_list	*pile_b;

	pile_a = ft_init_list(18, 23);
	ft_print_list(pile_a);
	pile_b = ft_init_list(37, 42);
	ft_print_list(pile_b);
	ft_free_list(pile_a);
	ft_free_list(pile_b);
	return (0);
}
