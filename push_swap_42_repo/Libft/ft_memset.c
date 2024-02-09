/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:41:49 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/23 09:52:48 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int value, size_t count)
{
	unsigned char	*ptr;
	size_t			count_2;

	count_2 = 0;
	ptr = (unsigned char *)s;
	while (count_2 < count)
	{
		ptr[count_2] = (unsigned char)value;
		count_2++;
	}
	return (ptr);
}
