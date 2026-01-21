/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 04:37:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/22 00:39:21 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

//min, max, checksorted, find index


int     ft_min(t_list *head)
{
    int i;

    i = head->content;
    while (head)
    {
        if (i > head->content)
        i = head->content;
        head = head->next;
    }
    ft_printf("min = %d\n", i);
    return (i);
}

int     ft_max(t_list *head)
{
    int i;

    i = head->content;
    while (head)
    {
        if (i < head->content)
            i = head->content;
        head = head->next;
    }
    ft_printf("max = %d\n", i);
    return (i);
}

void    sort_three(t_list **head)
{
    if (ft_min(*head) == (*head)->content)
    {
        reverse_rotate(head, 'a');
        swap(head, 'a');
    }
    else if (ft_max(*head) == (*head)->content)
    {
        rotate(head, 'a');
        if (is_sorted(head))
            swap(head, 'a');
    }
    else (ft_min(*head) != (*head)->content)
    {
        if (ft_max(*head) == ft_lstlast(*head))
            swap(head, 'a');
        else
            reverse_rotate(head, 'a');
    }
}

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


// verifier si je dois creer la  stack b meme si la len est de 2 ou pas
void    algo(t_list **heada)
{
    int len_a;

    len_a = ft_lstsize(*heada);
    if (len_a == 2)
        swap(heada, 'a');
    // else if (len_a == 3)
    // {
    //     three_nb(&heada);
    // }
    ft_min(*heada);
    ft_max(*heada);
    if (is_sorted(heada) == 1)
        ft_printf("sorted\n");
}