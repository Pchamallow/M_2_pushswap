/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:01:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/22 03:32:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "structures.h"
# include "libft/libft.h"




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


/***********************************************************************/
/*                         MOVES                                       */
/***********************************************************************/
// SWAP
void    swap(t_list **head, char c);
void    swapab(t_list **heada, t_list **headb);

// ROTATE
void	rotate(t_list	**head, char c);
void    rotateab(t_list **heada, t_list **headb);

// REVERSE ROTATE
void	reverse_rotate(t_list **head, char c);
void    reverse_rotateab(t_list **heada, t_list **headb);

// PUSH
void	push(t_list **source, t_list **target);
void	pusha(t_list **heada, t_list **headb);
void	pushb(t_list **heada, t_list **headb);


/***********************************************************************/
/*                         ALGO                                        */
/***********************************************************************/
void    algo(t_list **heada);
void    three_nb(t_list **head);
int     ft_min(t_list *head);
int     ft_max(t_list *head);
int     find_index(t_list *head, int i);
void    sort_three(t_list **head);

int find_index_b(t_list *head_b, int nbr_a);










#endif
