/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:36:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/13 10:33:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_isnum(char **av)
{
	int	x;
	int	y;

	x = 0;
	if (!av)
		return (0);
	while (av[x])
	{
		if (!ft_isdigit(av[x][0]) && av[x][0] != '-')
			return (0);
		if (av[x][0] == '-' && !av[x][1])
			return (0);
		y = 1;
		while (av[x][y])
		{
			if (ft_isdigit(av[x][y]) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static int	ft_skip_zeros(int num, char *str)
{
	int	zeros;

	zeros = 0;
	if (str && num)
	{
		if (num <= 0 && str[0] == '-')
			zeros++;
		while (str[zeros] && str[zeros] == '0')
			zeros++;
		if (!str[zeros])
			zeros--;
	}
	return (zeros);
}

int	ft_check_overflow(char **av)
{
	size_t	x;
	int		num;
	int		zeros;
	char	*copy;

	if (!av)
		return (0);
	x = 0;
	while (av[x])
	{
		num = ft_atoi(av[x]);
		zeros = ft_skip_zeros(num, av[x]);
		copy = ft_itoa(num);
		if (num < 0 && av[x][0] == '-')
			av[x][--zeros] = '-';
		if (ft_strncmp(copy, av[x] + zeros, ft_strlen(av[x])) != 0)
			return (free(copy), 0);
		if (num < 0 && zeros != 0 && av[x][zeros - 1])
			av[x][zeros] = '0';
		free(copy);
		x++;
	}
	return (1);
}

int	ft_check_doubles(char **av)
{
	int	x;
	int	y;

	x = 0;
	if (!av)
		return (0);
	while (av[x])
	{
		y = x + 1;
		while (av[x] && av[y])
		{
			if (ft_atoi(av[x]) == ft_atoi(av[y]))
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_check_arg(int ac, char **av)
{
	if (ac == 2)
		ft_one_arg_check(av[1]);
	else if (ac > 2)
	{
		if (ft_check_isnum(av + 1) == 0)
			ft_perror();
		if (ft_check_doubles(av + 1) == 0)
			ft_perror();
		if (ft_check_overflow(av + 1) == 0)
			ft_perror();
	}
	else
		exit(EXIT_FAILURE);
}
