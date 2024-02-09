/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:55:16 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/13 11:09:44 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_abs_fill(int *n, int *sign)
{
	if (*n < 0)
	{
		*n = -(*n);
		*sign = 1;
	}
	else
		*sign = 0;
}

static char	*ft_fill(char *str, int n, int len, int sign)
{
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	len = ft_len(n);
	ft_abs_fill(&n, &sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n <= -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	if (n == 0)
	{
		ft_strlcpy(str, "0", 2);
		return (str);
	}
	str = ft_fill(str, n, len, sign);
	return (str);
}
