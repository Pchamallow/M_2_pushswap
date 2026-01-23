/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:01:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 23:04:12 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "structures.h"
// # include "libft/libft.h"
# include "unistd.h"

/***********************************************************************/
/*                         PARSING                                     */
/***********************************************************************/
void	ft_pushpa(t_list **stacka, t_list **stackb);
int		lengthlist(char **argv);
int		strargs(char **argv);
int     createstacka(t_list **head, long number);
int     ft_createstackb(t_list **head);
void	printlist(t_list *head);
void	tester(t_list **heada, t_list **headb);
void    printerror(void);
int     digit_or_space(char **str, int argc);
void	fillstacka(long number, t_list *head);
int     number_to_stack(int argc, char **argv, t_list **head);
int     extract_numbers(char *str, t_list **head);
int     ft_free(char *tab);
void    clearlist(t_list **head);
int     end_number(char *str, int i);
int     is_sorted(t_list **head);
int     is_int_minmax(char *numstr);
int     is_duplicated(t_list **head);
int     valid_sign(char *str);
char    *fill_stacka(char *str, int i, t_list **head);
int     is_number(char *str);
int     is_empty(char *str);
int     parse(int argc, char **argv, t_list **heada);
int	security(int argc, char **argv, t_list *a);

/***********************************************************************/
/*                         MOVES                                       */
/***********************************************************************/
// SWAP
void    swap(t_list **head, char c);
void    swapab(t_list **heada, t_list **headb);

// ROTATE
void	rotate(t_list	**stack, char c);
void    rotateab(t_list **heada, t_list **headb);

// REVERSE ROTATE
void	reverse_rotate(t_list **head, char c);
void    reverse_rotateab(t_list **heada, t_list **headb);

// PUSH
void	push(t_list **source, t_list **target, char c);

/***********************************************************************/
/*                         ALGO                                        */
/***********************************************************************/
int     set_chunk(int size);
void    apply_butterfly(t_list **a, t_list **b);
void    fill_index(t_list *a);
void    b_to_a_index(t_list **a, t_list **b);
void	b_to_a_content(t_list **a, t_list **b);
int     max_index(t_list *b);
void    butterfly(t_list **a);
void	algorithm(t_list **a, t_list **b);
void sort_little_stack(t_list **a, t_list **b);
void	sort_four_to_five(t_list **a, t_list **b);
int	only_null(t_list *a);


void    three_nb(t_list **head);
int     ft_min(t_list *head);
int     ft_max(t_list *head);
int     find_index(t_list *head, int i);
void    sort_three(t_list **head);

int cost(int len, int index, int reverse);
int target_index(t_list *head_b, int nbr);
int find_index(t_list *head_b, int nbr);
void put_best(t_list **head_a, t_list **head_b, int nbr);
void    print_step(t_list *head, char *str);

void b_to_empty(t_list **head_a, t_list **head_b);
void    sort_nbr(t_list **head_a, t_list **head_b);



int case_rarb(t_list *head_a, t_list *head_b, int nbr);
int case_rrr(t_list *head_a, t_list *head_b, int nbr);
int case_rarrb(t_list *head_a, t_list *head_b, int nbr);
int case_rrarb(t_list *head_a, t_list *head_b, int nbr);



void    apply_rr(t_list **head_a, t_list **head_b, int nbr);
void    apply_rrarrb(t_list **head_a, t_list **head_b, int nbr);
void    apply_rrarb(t_list **head_a, t_list **head_b, int nbr);
void    apply_rarrb(t_list **head_a, t_list **head_b, int nbr);





#endif
