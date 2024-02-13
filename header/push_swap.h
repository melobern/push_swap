/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:57:01 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/09 09:55:51 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_nodes_list
{
	int					value;
	bool				top_three;
	size_t				cost;
	size_t				pos;
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
int					ft_isspace(int n);
int					ft_search_char(char letter, char *charset);
void				ft_fill_spaces(char *str);
char				**ft_split_set(char const *s, char *tokens);
void				ft_free_tab(char **tab);
void				ft_perror(void);
size_t				abs_diff(size_t one, size_t two);
////////////////////////////////////////////////////////////////
////////			CHECKS			////////
////////////////////////////////////////////////////////////////
int					ft_check_isnum(char **av);
int					ft_check_doubles(char **av);
int					ft_check_overflow(char **av);
void				ft_one_arg_check(char *av);
void				ft_check_arg(int ac, char **av);
////////////////////////////////////////////////////////////////
////////			SWAP			////////
////////////////////////////////////////////////////////////////
void				ft_swap(int *a, int *b);
void				ft_swap_bool(bool *a, bool *b);
void				ft_swap_size_t(size_t *a, size_t *b);
void				ft_swap_node(t_nodes_list *a, t_nodes_list *b);
////////////////////////////////////////////////////////////////
////////			COMMANDS		////////
////////////////////////////////////////////////////////////////
char				*sa(t_nodes_list **pile_a);
char				*sb(t_nodes_list **pile_b);
char				*ss(t_nodes_list **pile_a, t_nodes_list **pile_b);
char				*pa(t_nodes_list **pile_a, t_nodes_list **pile_b);
char				*pb(t_nodes_list **pile_b, t_nodes_list **pile_a);
char				*ra(t_nodes_list **pile_a);
char				*rb(t_nodes_list **pile_b);
char				*rr(t_nodes_list **pile_a, t_nodes_list **pile_b);
char				*rra(t_nodes_list **pile_a);
char				*rrb(t_nodes_list **pile_b);
char				*rrr(t_nodes_list **pile_a, t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////		CHOSE COMMANDS			////////
////////////////////////////////////////////////////////////////
void				ss_or_sb(t_nodes_list **a, t_nodes_list **b,
						size_t len);
void				rb_or_rrb(t_nodes_list **b, size_t *len,
						size_t position);
void				roll_a(bool direction, t_nodes_list **pile_a);
void				roll_b(bool direction, t_nodes_list **pile_b);
bool				down_or_up(size_t pos, t_nodes_list **pile);
////////////////////////////////////////////////////////////////
////////			SORT			////////
////////////////////////////////////////////////////////////////
bool				pile_sorted(t_nodes_list **pile);
bool				pile_rev_sorted(t_nodes_list **pile);
bool				pos_linear(t_nodes_list **pile);
bool				sorted_if_rotated(t_nodes_list **pile);
bool				is_min(size_t num, t_nodes_list **pile);
bool				is_max(size_t num, t_nodes_list **pile);
bool				is_min_max(size_t num, t_nodes_list **pile);
bool				is_top_three(t_nodes_list *pile);
bool				down_or_up(size_t pos, t_nodes_list **pile);
void				first_sort(t_nodes_list pile_a, size_t len);
void				sort_three(t_nodes_list **pile);
void				push_swap(t_nodes_list **pile_a, t_nodes_list **pile_b);
void				push_into_b(t_nodes_list **pile_a,
							t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////			CALCULS			////////
////////////////////////////////////////////////////////////////
size_t				near(t_nodes_list *pile_a, t_nodes_list **pile_b);
size_t				calcul_pos(t_nodes_list *pile_a, t_nodes_list **pile_b);
void				calcul_cost(t_nodes_list **a, t_nodes_list **b,
							size_t len);
size_t				search_cheaper_a(t_nodes_list **a, t_nodes_list **b,
							size_t len);
size_t				search_min(t_nodes_list **pile);
void				sync_rotate_b(t_nodes_list **a, t_nodes_list **b,
							size_t a_len);
////////////////////////////////////////////////////////////////
////////			LIST			////////
////////////////////////////////////////////////////////////////
size_t				fill_pile(t_nodes_list **pile, char **av);
size_t				pile_len(t_nodes_list **pile);
void				free_pile(t_nodes_list **pile);
void				assign_nodes(t_nodes_list **pile, size_t len);

#endif
