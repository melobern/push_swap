/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:43:21 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/19 10:38:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_one_arg_check(char *av)
{
	char	**args;
	int	x;
	int	len;

	x = 0;
	args = ft_splitPISCINE(av, ' ');
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
