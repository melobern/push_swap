/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 08:36:17 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/19 10:06:33 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_isnum(char **av)
{
	int	x;
	int	y;

	x = 1;
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
	if (num <= 0 && str[0] == '-')
		str++;
	while (str && str[0] == '0')
	{
		str++;
		zeros++;
	}
	return (zeros);
}

static int	ft_check_overflow(char **av)
{
	size_t	x;
	size_t	len;
	int		num;
	char	*copy;

	x = 0;
	while (av[++x])
	{
		num = ft_atoi(av[x]);
		(av[x]) += ft_skip_zeros(num, av[x]);
		if (num == 0 && (!av[x] || (av[x][0] == '0' && !av[x][1])))
			return (1);
		else if (num < 0)
			av[x][0] = '-';
		len = ft_strlen(av[x]);
		if (len > 11 || (num == -1 && len > 2))
			return (0);
		copy = ft_itoa(num);
		if (ft_strncmp(copy, av[x], len) != 0)
			return (free(copy), 0);
		free(copy);
	}
	return (1);
}

static int	ft_check_doubles(char **av)
{
	int	x;
	int	y;

	x = 1;
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
	if (av == 2)
		ft_one_arg_check(av[1]);
	else if (av > 2)
	{
		if (ft_check_isnum(av) == 0)
			ft_perror();
		if (ft_check_doubles(av) == 0)
			ft_perror();
		if (ft_check_overflow(av) == 0)
			ft_perror();
	}
	else
		exit(EXIT_FAILURE);
}
