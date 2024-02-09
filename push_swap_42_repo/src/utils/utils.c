/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:50:07 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 15:20:02 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	malloc_error(void)
{
	write(2, "Malloc error\n", 13);
	exit(EXIT_FAILURE);
}

int	ft_search_char(char letter, char *charset)
{
	int	c;

	c = 0;
	if (charset)
	{
		while (charset[c])
		{
			if (letter == charset[c])
				return (1);
			c++;
		}
	}
	return (0);
}

size_t	abs_diff(size_t one, size_t two)
{
	if (!one || !two)
		return (0);
	if (one > two)
		return (one - two);
	return (two - one);
}
