/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:37 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/21 17:36:01 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len_tab(char const *s, char *tokens)
{
	int	len_tab;
	int	check;

	len_tab = 0;
	check = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (!ft_search_char(*s, tokens))
		{
			if (check == 0)
				len_tab++;
			check = 1;
		}
		else
			check = 0;
		s++;
	}
	return (len_tab);
}

static char	*ft_write_word(char *s, char *tokens, int *cursor)
{
	int		len;
	char	*word;

	len = 0;
	while (ft_search_char(s[*cursor], tokens))
		(*cursor)++;
	while (s[len + *cursor] && !ft_search_char(s[len + *cursor], tokens))
		len++;
	word = ft_substr(s, *cursor, len);
	*cursor += len;
	return (word);
}

void	ft_free_tab(char **tab)
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

char	**ft_split_set(char const *s, char *tokens)
{
	char	**tab;
	int		len_tab;
	int		i;
	int		cursor;

	len_tab = ft_len_tab(s, tokens);
	tab = (char **)malloc(sizeof(char *) * (len_tab + 1));
	if (!tab)
		return (NULL);
	i = 0;
	cursor = 0;
	while (i < len_tab)
	{
		tab[i] = ft_write_word((char *)s, tokens, &cursor);
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
