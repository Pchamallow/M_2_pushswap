/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:01:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/12 23:19:26 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "structures.h"
# include "libft/libft.h"
/*
Theorie 1 :
1. mettre les chiffres dans une str avec un strjoin avec des espaces entre chaque nombre
2. stack_a convertir la str en stack
3. stack_b trier la stack
*/

//
//SOURCE
// void	ft_createstka(void);
void	ft_fillstka(t_list **head, char *nb);



#endif
