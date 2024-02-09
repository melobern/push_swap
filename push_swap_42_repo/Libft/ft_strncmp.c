/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:17:38 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/13 10:31:08 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		count;
	const char	*p1;
	const char	*p2;

	count = 0;
	p1 = s1;
	p2 = s2;
	if (!p1[count] && n > 0)
		return (-p2[count]);
	while ((p1[count] || p2[count]) && count < n)
	{
		if (p1[count] != p2[count])
			return ((unsigned char)p1[count] - (unsigned char)p2[count]);
		count++;
	}
	return (0);
}
