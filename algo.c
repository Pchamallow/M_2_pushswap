/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 04:37:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/20 23:41:49 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

// int     ft_min()
// {
    
// }

// a mettre dans une fonction qui push dans 3, 
// tant qu il n y  apas 3 nb restant
// envoyer sil y a 4 et 5 chiffres (trier par trois puis 
// mettre en fonction du necessaire)
// void   three_nb(t_list **head)
// {
//     t_list *first;
//     t_list *second;
//     t_list *third;

//     first = *head;
//     second = (*head)->next;
//     third = (*head)->next->next;
//     if (first > second)
//     {
//         swap(head, 'a');
//         if (third < second)
//             reverse_rotate(head, 'a');
//         else if (third < first)
//             ;
//     }
// }

// void    algo(t_list **heada)
// {
//     int len_a;

//     len_a = ft_lstsize(*heada);
//     if (len_a == 2)
//         swap(heada, 'a');
//     else if (len_a == 3)
//     {
//         three_nb(&heada);
//     }
//     if (is_sorted(heada) == 1)
//         ft_printf("sorted\n");
// }