/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:57:01 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/04 16:38:19 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_nodes_list
{
	int					value;
	int					cost;
	bool					top_three;
	bool					is_min;
	int					cheapest;
	size_t				index;
	size_t				pos;
	struct s_nodes_list	*target;
	struct s_nodes_list	*next;
	struct s_nodes_list	*prev;
}						t_nodes_list;
////////////////////////////////////////////////////////////////
///				TO REMOVE		////////
# include <stdio.h> ////////
////////
void	show_pile(t_nodes_list **pile); ////////
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
////////			UTILS			////////
////////////////////////////////////////////////////////////////
int						ft_isspace(int n);
int						ft_search_char(char letter, char *charset);
void					ft_fill_spaces(char *str);
char					**ft_split_set(char const *s, char *tokens);
void					ft_free_tab(char **tab);
void					ft_perror(void);
////////////////////////////////////////////////////////////////
////////			CHECKS			////////
////////////////////////////////////////////////////////////////
int						ft_check_isnum(char **av);
int						ft_check_doubles(char **av);
int						ft_check_overflow(char **av);
void					ft_one_arg_check(char *av);
void					ft_check_arg(int ac, char **av);
////////////////////////////////////////////////////////////////
////////			SWAP			////////
////////////////////////////////////////////////////////////////
void					ft_swap(int *a, int *b);
void					ft_swap_bool(bool *a, bool *b);
void					ft_swap_size_t(size_t *a, size_t *b);
void					ft_swap_node(t_nodes_list *a, t_nodes_list *b);
////////////////////////////////////////////////////////////////
////////			COMMANDS		////////
////////////////////////////////////////////////////////////////
char					*sa(t_nodes_list **pile_a);
char					*sb(t_nodes_list **pile_b);
char					*ss(t_nodes_list **pile_a, t_nodes_list **pile_b);
char					*pa(t_nodes_list **pile_a, t_nodes_list **pile_b);
char					*pb(t_nodes_list **pile_b, t_nodes_list **pile_a);
char					*ra(t_nodes_list **pile_a);
char					*rb(t_nodes_list **pile_b);
char					*rr(t_nodes_list **pile_a, t_nodes_list **pile_b);
char					*rra(t_nodes_list **pile_a);
char					*rrb(t_nodes_list **pile_b);
char					*rrr(t_nodes_list **pile_a, t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////			SORT			////////
////////////////////////////////////////////////////////////////
int						pile_sorted(t_nodes_list **pile);
int						pile_rev_sorted(t_nodes_list **pile);
int						pos_linear(t_nodes_list **pile);
int						is_top_three(t_nodes_list *pile);
int						is_min(int num, t_nodes_list **pile);
int						is_max(int num, t_nodes_list **pile);
int						is_min_max(int num, t_nodes_list **pile);
void					first_sort(t_nodes_list pile_a, size_t len);
void					sort_three(t_nodes_list **pile);
void					rev_sort(t_nodes_list **pile);
//void					sort_rev_three(t_nodes_list **pile);
void					push_swap(t_nodes_list **pile_a, t_nodes_list **pile_b);
void					push_into_b(t_nodes_list **pile_a,
							t_nodes_list **pile_b);
void					push_into_a(t_nodes_list **pile_a,
							t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////			LIST			////////
////////////////////////////////////////////////////////////////
size_t					fill_pile(t_nodes_list **pile, char **av);
size_t					pile_len(t_nodes_list **pile);
void					free_pile(t_nodes_list **pile);
void					assign_nodes(t_nodes_list **pile, size_t len);

#endif
