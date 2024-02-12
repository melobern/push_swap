/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:37 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/22 12:56:53 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_tab(char const *s, char c)
{
	int	len_tab;
	int	check;

	len_tab = 0;
	check = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			if (check == 0)
				len_tab++;
			check = 1;
		}
		else if (*s == c)
			check = 0;
		s++;
	}
	return (len_tab);
}

static char	*ft_write_word(char *s, char c, int *cursor)
{
	int		len;
	char	*word;

	len = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[len + *cursor] && s[len + *cursor] != c)
		len++;
	word = ft_substr(s, *cursor, len);
	*cursor += len;
	return (word);
}

static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		len_tab;
	int		i;
	int		cursor;

	len_tab = ft_len_tab(s, c);
	tab = (char **)malloc(sizeof(char *) * (len_tab + 1));
	if (!tab)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < len_tab)
	{
		tab[i] = ft_write_word((char *)s, c, &cursor);
		if (!tab[i])
		{
			ft_free_tab(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}
