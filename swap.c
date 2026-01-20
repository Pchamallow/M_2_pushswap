/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:28:19 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/20 00:47:23 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

 ///////////////////////////    SWAP    ///////////////////////////////////////////////////////////
// 2nd become 1st 
void swap(t_list **head, char c)
{
    t_list *first = *head;
    t_list *second = (*head)->next;
    t_list *third = (*head)->next->next;

    second->next = first;
    first->next = third;
    *head = second;
    if (c == 'a')
		ft_printf("%s", "sa\n");
	if (c == 'b')
		ft_printf("%s", "sb\n");
	return ;
}

void swapab(t_list **heada, t_list **headb)
{
	swap(heada, 'c');
    swap(headb, 'c');
	ft_printf("%s", "ss\n");
}
