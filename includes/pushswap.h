/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:01:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/31 19:48:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include "unistd.h"
# include <stdlib.h>

/***********************************************************************/
/*                         PARSING                                     */
/***********************************************************************/
int		lengthlist(char **argv);
int		strargs(char **argv);
int		create_stack_a(t_list **head, long number);
int		digit_or_space(char **str, int argc);
int		number_to_stack(int argc, char **argv, t_list **head);
int		extract_numbers(char *str, t_list **head);
int		end_number(char *str, int i);
int		is_sorted(t_list **head);
int		is_int_minmax(char *numstr);
int		is_duplicated(t_list **head);
int		valid_sign(char *str);
char	*fill_stacka(char *str, int i, t_list **head);
int		is_number(char *str);
int		is_empty(char *str);
int		only_null(t_list *a);
int		parse(int argc, char **argv, t_list **heada);

/***********************************************************************/
/*                         MOVES                                       */
/***********************************************************************/
void	swap(t_list **head, char c);
void	push(t_list **source, t_list **target, char c);
void	rotate(t_list	**stack, char c);
void	reverse_rotate(t_list **head, char c);

/***********************************************************************/
/*                         ALGO                                        */
/***********************************************************************/
void	fill_index(t_list *a);
void	b_to_a_index(t_list **a, t_list **b);
void	b_to_a_content(t_list **a, t_list **b);
int		max_index(t_list *b);
void	sort_three(t_list **head);
void	sort_little_stack(t_list **a, t_list **b);
void	sort_four_to_five(t_list **a, t_list **b);
void	rotate_min_a(t_list **a);
int		index_insert(t_list *a, int nbr);
int		ft_min(t_list *head);
int		ft_max(t_list *head);
int		find_index(t_list *head_b, int nbr);
void	butterfly(t_list **a);
void	apply_butterfly(t_list **a, t_list **b);
void	algorithm(t_list **a, t_list **b);

#endif
