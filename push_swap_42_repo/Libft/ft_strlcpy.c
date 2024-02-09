/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:28:38 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/09 18:25:11 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_size;

	src_size = 0;
	if (size > 0)
	{
		while (src[src_size] && src_size < size - 1)
		{
			dest[src_size] = src[src_size];
			src_size++;
		}
		dest[src_size] = '\0';
	}
	while (src[src_size])
		src_size++;
	return (src_size);
}
