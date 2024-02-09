/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:01:02 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/13 18:19:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	size_t	x;

	if (s == NULL || f == NULL)
		return (NULL);
	x = 0;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s, ft_strlen((char *)s) + 1);
	while (ptr[x])
	{
		ptr[x] = (*f)(x, ptr[x]);
		x++;
	}
	return (ptr);
}
