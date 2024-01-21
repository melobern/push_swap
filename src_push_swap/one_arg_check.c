/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:43:21 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/21 19:45:06 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_spaces(char *str)
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
	/*
	if (!ft_isdigit(av[0]) && !ft_search_char(av[0], " -"))
		ft_perror();
	while (++x < len)
	{
		if (!ft_isdigit(av[x]) && !ft_isspace(av[x - 1]))
			ft_perror();
		if (!ft_isdigit(av[x]) && !ft_search_char(av[x], " -"))
			ft_perror();
	}
	*/
