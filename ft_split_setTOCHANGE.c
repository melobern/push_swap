/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_setTOCHANGE.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 09:47:37 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/19 11:10:32 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "push_swap.h"
*/
////////////////////////////////////////////////////////////////////////////////
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*copy;
	unsigned char	*ptr;
	size_t			count;

	if (nmemb && size && ((nmemb * size) / nmemb != size))
		return (NULL);
	size = nmemb * size;
	count = 0;
	copy = (void *)malloc(size);
	if (!(copy))
		return (NULL);
	ptr = (unsigned char *)copy;
	while (count < size)
	{
		ptr[count] = (unsigned char)0;
		count++;
	}
	return (ptr);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	c;

	c = 0;
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (c < len)
	{
		str[c] = (char)s[start + c];
		c++;
	}
	str[c] = '\0';
	return (str);
}

int	ft_search_char(char letter, char *charset)
{
	int	c;

	c = 0;
	if (charset)
	{
		while (charset[c])
		{
			if (letter == charset[c])
				return (1);
			c++;
		}
	}
	return (0);
}

////////////////////////////////////////////////////////////////////////////////
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

int	main(int ac, char **av)
{
	char **tab;
	int	x;

	x = 0;
	if (ac > 1)
	{
		tab = ft_split_set(av[1], av[2]);
		while (tab[x])
		{
			printf("%s\n", tab[x]);
			x++;
		}
	}
	ft_free_tab(tab);
	return (0);
}
