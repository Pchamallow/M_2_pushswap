/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:01:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/13 02:48:41 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "structures.h"
# include "libft/libft.h"

//SOURCE
// void	ft_createstka(void);
void	filllist(t_list *head);
void	ft_pushpa(t_list **stacka, t_list **stackb);
int		lengthlist(char **argv);
int		printerror(void);
int		isalphabet(char *arguments);
int		strargs(char **argv);
int     ft_createstack(t_list **head);
void	printlist(t_list *head);
void	tester(t_list **heada, t_list **headb);




/////////////////////////// MOVES
//SWAP
void	swap(t_list **head);
void    swapa(t_list **head);
void    swapb(t_list **head);
//ROTATE
void	rotate(t_list **head);
void    rotatea(t_list **head);
void    rotateb(t_list **head);
//REVERSE ROTATE
void	reverserotate(t_list **head);
void	reverserotatea(t_list **head);
void	reverserotateb(t_list **head);





#endif
