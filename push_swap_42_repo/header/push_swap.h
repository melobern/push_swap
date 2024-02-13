/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:57:01 by mbernard          #+#    #+#             */
/*   Updated: 2024/02/13 17:57:31 by mbernard         ###   ########.fr       */
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
	bool				top_one;
	size_t				cost;
	size_t				pos;
	size_t				bin_num;
	struct s_nodes_list	*next;
	struct s_nodes_list	*prev;
}						t_nodes_list;
////////////////////////////////////////////////////////////////
////////			UTILS			////////
////////////////////////////////////////////////////////////////
int			ft_search_char(char letter, char *charset);
void		ft_fill_spaces(char *str);
char		**ft_split_set(char const *s, char *tokens);
void		ft_free_tab(char **tab);
void		ft_perror(void);
void		malloc_error(void);
size_t		abs_diff(size_t one, size_t two);
//size_t		dec_to_bin(size_t num);
////////////////////////////////////////////////////////////////
////////			CHECKS			////////
////////////////////////////////////////////////////////////////
int			ft_check_isnum(char **av);
int			ft_check_doubles(char **av);
int			ft_check_overflow(char **av);
void		ft_one_arg_check(char *av);
void		ft_check_arg(int ac, char **av);
////////////////////////////////////////////////////////////////
////////			COMMANDS		////////
////////////////////////////////////////////////////////////////
void		ft_swap_node(t_nodes_list *a, t_nodes_list *b);
char		*sa(t_nodes_list **pile_a);
char		*sb(t_nodes_list **pile_b);
char		*ss(t_nodes_list **pile_a, t_nodes_list **pile_b);
char		*pa(t_nodes_list **pile_a, t_nodes_list **pile_b);
char		*pb(t_nodes_list **pile_b, t_nodes_list **pile_a);
char		*ra(t_nodes_list **pile_a);
char		*rb(t_nodes_list **pile_b);
char		*rr(t_nodes_list **pile_a, t_nodes_list **pile_b);
char		*rra(t_nodes_list **pile_a);
char		*rrb(t_nodes_list **pile_b);
char		*rrr(t_nodes_list **pile_a, t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////		CHOSE COMMANDS			////////
////////////////////////////////////////////////////////////////
void		ra_or_rr(t_nodes_list **a, t_nodes_list **b);
void		ss_or_sb(t_nodes_list **a, t_nodes_list **b, size_t len);
void		rb_or_rrb(t_nodes_list **b, size_t *len, size_t position);
void		roll_a(bool direction, t_nodes_list **pile_a);
void		roll_b(bool direction, t_nodes_list **pile_b);
////////////////////////////////////////////////////////////////
////////			SORT			////////
////////////////////////////////////////////////////////////////
bool		pile_sorted(t_nodes_list **pile);
bool		pile_rev_sorted(t_nodes_list **pile);
bool		pos_linear(t_nodes_list **pile);
bool		is_min(size_t num, t_nodes_list **pile);
bool		is_min_max(size_t num, t_nodes_list **pile);
bool		is_top_three(t_nodes_list *pile);
bool		down_or_up(size_t pos, t_nodes_list **pile);
void		sort_three(t_nodes_list **pile);
void		push_into_b(t_nodes_list **pile_a, t_nodes_list **pile_b);
void		radix_sort(t_nodes_list **a, t_nodes_list **b, size_t len);
////////////////////////////////////////////////////////////////
////////			CALCULS			////////
////////////////////////////////////////////////////////////////
size_t		near(t_nodes_list *pile_a, t_nodes_list **pile_b);
size_t		calcul_pos(t_nodes_list *pile_a, t_nodes_list **pile_b);
void		calcul_cost(t_nodes_list **a, t_nodes_list **b, size_t len);
size_t		search_min(t_nodes_list **pile);
////////////////////////////////////////////////////////////////
////////			LIST			////////
////////////////////////////////////////////////////////////////
size_t		fill_pile(t_nodes_list **pile, char **av);
size_t		pile_len(t_nodes_list **pile);
void		free_pile(t_nodes_list **pile);
void		assign_nodes(t_nodes_list **pile, size_t len);

#endif
