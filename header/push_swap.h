/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:57:01 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/24 15:44:47 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_nodes_list {
	int	value;
	int	index;
	int	cost;
	int	above_median;
	int	cheapest;
	struct s_nodes_list *target;
	struct s_nodes_list *next;
	struct s_nodes_list *prev;
}	t_nodes_list;
////////////////////////////////////////////////////////
///				TO REMOVE		////////
# include <stdio.h>	 				////////
void	show_pile(t_nodes_list **pile);
///				 			////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////			UTILS			////////
////////////////////////////////////////////////////////////////
int		ft_isspace(int n);
void	ft_fill_spaces(char *str);
int		ft_search_char(char letter, char *charset);
char	**ft_split_set(char const *s, char *tokens);
void	ft_free_tab(char **tab);
void	ft_perror(void);
////////////////////////////////////////////////////////////////
////////			CHECKS			////////
////////////////////////////////////////////////////////////////
int		ft_check_isnum(char **av);
int		ft_check_doubles(char **av);
int		ft_check_overflow(char **av);
void	ft_one_arg_check(char *av);
void	ft_check_arg(int ac, char **av);
////////////////////////////////////////////////////////////////
////////			COMMANDS		////////
////////////////////////////////////////////////////////////////
void	ft_swap(int *a, int *b);
char	*sa(t_nodes_list **pile_a);
char	*sb(t_nodes_list **pile_b);
char	*ss(t_nodes_list **pile_a, t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////			SORT			////////
////////////////////////////////////////////////////////////////
int	pile_sorted(t_nodes_list **pile);
void	sort_three(t_nodes_list **pile);
void	push_swap(t_nodes_list **pile_a, t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////			LIST			////////
////////////////////////////////////////////////////////////////
void	fill_pile(t_nodes_list **pile, char **av);
void	free_pile(t_nodes_list **pile);
size_t	pile_len(t_nodes_list **pile);

#endif

/*
 * Un nom de typedef doit commencer par t_
 */
