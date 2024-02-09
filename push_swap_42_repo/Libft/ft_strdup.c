/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:49:46 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/09 11:33:40 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		count;

	copy = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!(copy))
		return (NULL);
	count = 0;
	while (s[count])
	{
		copy[count] = s[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}
