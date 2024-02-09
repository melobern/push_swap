/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:57:38 by mbernard          #+#    #+#             */
/*   Updated: 2023/11/20 15:16:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_c;

	new_c = (t_list *)malloc(sizeof(t_list));
	if (!new_c)
		return (NULL);
	new_c->content = content;
	new_c->next = NULL;
	return (new_c);
}
