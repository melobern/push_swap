/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:54:10 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/09 22:33:17 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	c;
	size_t	c_f;
	char	*p_str;
	char	*p_find;

	c = 0;
	p_str = (char *)str;
	p_find = (char *)to_find;
	if (!(p_find[0]))
		return (p_str);
	while (p_str[c] != '\0' && c < len)
	{
		c_f = 0;
		while (p_str[c + c_f] == p_find[c_f] && c + c_f < len)
		{
			c_f++;
			if (p_find[c_f] == '\0')
				return (p_str + c);
		}
		c++;
	}
	return (NULL);
}
