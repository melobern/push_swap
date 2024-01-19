/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:43:21 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/19 11:20:17 by mbernard         ###   ########.fr       */
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
	space[5] = 32;
	space[6] = 0;
}

void	ft_one_arg_check(char *av)
{
	char	**args;
	int		len;
	char	spaces[6];
	int		x;

	x = 0;
	ft_fill_spaces(spaces);
	args = ft_split_set(av, spaces);

	len = ft_strlen(av);
	if (!ft_isdigit(av[0]) && !ft_search_char(av[0], " -"))
		ft_perror();
	while (++x < len)
	{
		if (!ft_isdigit(av[x]) && !ft_isspace(av[x - 1]))
			ft_perror();
		if (!ft_isdigit(av[x]) && !ft_search_char(av[x], " -"))
			ft_perror();
	}
}
