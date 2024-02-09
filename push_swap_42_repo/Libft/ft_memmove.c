/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:25:41 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/09 19:00:04 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_ptr;
	char	*src_ptr;
	size_t	c;

	dest_ptr = (char *)dest;
	src_ptr = (char *)src;
	c = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest_ptr > src_ptr && dest_ptr <= src_ptr + n)
	{
		while (n-- > 0)
			dest_ptr[n] = src_ptr[n];
	}
	else
	{
		while (c < n)
		{
			dest_ptr[c] = src_ptr[c];
			c++;
		}
	}
	return (dest);
}
