/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:19:45 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/09 10:57:13 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	dest_size;
	size_t	src_size;

	count = 0;
	dest_size = 0;
	src_size = 0;
	while (dest[dest_size] && dest_size < size)
		dest_size++;
	while (src[src_size])
		src_size++;
	if (size == 0 || dest_size == size)
		return (src_size + size);
	while (src[count] && dest_size + count < size - 1)
	{
		dest[dest_size + count] = src[count];
		count++;
	}
	dest[dest_size + count] = '\0';
	return (src_size + dest_size);
}
