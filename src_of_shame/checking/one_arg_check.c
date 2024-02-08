/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:43:21 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/01 10:27:15 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_spaces(char *str)
{
	int	x;
	int	space;

	x = 0;
	space = 9;
	while (x < 5)
	{
		str[x] = space;
		x++;
		space++;
	}
	str[5] = 32;
	str[6] = 0;
}

void	ft_one_arg_check(char *av)
{
	char	**args;
	char	spaces[7];

	ft_fill_spaces(spaces);
	args = ft_split_set(av, spaces);
	if (!args || !args[1])
		exit(EXIT_FAILURE);
	if (ft_check_isnum(args) == 0)
	{
		ft_free_tab(args);
		ft_perror();
	}
	if (ft_check_doubles(args) == 0)
	{
		ft_free_tab(args);
		ft_perror();
	}
	if (ft_check_overflow(args) == 0)
	{
		ft_free_tab(args);
		ft_perror();
	}
	ft_free_tab(args);
}
