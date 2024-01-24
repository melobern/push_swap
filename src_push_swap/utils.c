/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:50:07 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/24 14:01:15 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_perror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isspace(int n)
{
	return ((n > 8 && n < 14) || n == 32);
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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
