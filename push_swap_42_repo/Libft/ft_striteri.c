/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:22:47 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/13 18:38:26 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	x;
	unsigned int	len;

	x = 0;
	len = (unsigned int)ft_strlen(s);
	if (s != NULL && f != NULL)
	{
		while (x < len)
		{
			(*f)(x, s);
			x++;
			s++;
		}
	}
}
