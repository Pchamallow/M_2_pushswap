/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:01:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/19 22:56:05 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "structures.h"
# include "libft/libft.h"

//SOURCE
// void	ft_createstka(void);
void	ft_pushpa(t_list **stacka, t_list **stackb);
int		lengthlist(char **argv);
int		strargs(char **argv);
int     createstacka(t_list **head, long number);
int     ft_createstackb(t_list **head);
void	printlist(t_list *head);
void	tester(t_list **heada, t_list **headb);



/***********************************************************************/
/*                         PARSING                                     */
/***********************************************************************/
void    printerror(void);
int     isalphabet(char **arguments);
void	fillstacka(long number, t_list *head);
int     number_to_stack( char **argv, t_list **head);
int     extract_numbers(char *str, t_list **head);
int     parse(char **argv, t_list **heada);
int     ft_free(char *tab);
void    clearlist(t_list **head);
int     end_number(char *str, int i);
int     is_sorted(t_list **head);
int     is_int_minmax(char *numstr);
int     is_duplicated(t_list **head);
int     valid_sign(char *str);
char *fill_stacka(char *str, int i, t_list **head);









/////////////////////////// MOVES
// SWAP
void	swap(t_list **head);
void    swapa(t_list **head);
void    swapb(t_list **head);
void    swapab(t_list **heada, t_list **headb);

// ROTATE
void	rotate(t_list **head);
void    rotatea(t_list **head);
void    rotateb(t_list **head);
void    rotateab(t_list **heada, t_list **headb);

// REVERSE ROTATE
void	reverserotate(t_list **head);
void	reverserotatea(t_list **head);
void	reverserotateb(t_list **head);
void    reverserotateab(t_list **heada, t_list **headb);

// PUSH
void	push(t_list **source, t_list **target);
void	pusha(t_list **heada, t_list **headb);
void	pushb(t_list **heada, t_list **headb);







#endif
