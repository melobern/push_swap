/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:57:01 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/18 10:01:44 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

void				ft_check_arg(int ac, char **av);
void				swap(t_list *a, t_list *b);
char				*sa(t_list pile_a);
char				*sb(t_list pile_b);
char				*ss(t_list pile_a, t_list pile_b);

#endif

/*
 * Un nom de typedef doit commencer par t_
 */
