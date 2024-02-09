/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:02:54 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/16 14:07:06 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			x;
	const char	*ptr;

	x = ft_strlen(s);
	ptr = (char *)s;
	while (x >= 0)
	{
		if (ptr[x] == (char)c)
			return ((char *)ptr + x);
		x--;
	}
	return (NULL);
}
