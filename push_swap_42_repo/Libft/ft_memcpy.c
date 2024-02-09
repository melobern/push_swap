/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:55:42 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/09 18:50:34 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	c;
	char	*dest_ptr;

	if (!dst && !src)
		return (0);
	dest_ptr = (char *)dst;
	c = 0;
	while (c < n)
	{
		*(char *)dest_ptr = *(char *)src;
		dest_ptr++;
		src++;
		c++;
	}
	return (dst);
}
