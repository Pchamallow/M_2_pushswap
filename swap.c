/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:28:19 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/14 18:43:13 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

 ///////////////////////////    SWAP    ///////////////////////////////////////////////////////////
// 2nd become 1st 
void swap(t_list **head)
{
    t_list *first = *head;
    t_list *second = (*head)->next;
    t_list *third = (*head)->next->next;

    second->next = first;
    first->next = third;
    *head = second;
	return ;
}

void swapa(t_list **head)
{
	swap(head);
	ft_printf("%s", "sa\n");
}

void swapb(t_list **head)
{
	swap(head);
	ft_printf("%s", "sb\n");
}

void swapab(t_list **heada, t_list **headb)
{
	swap(heada);
    swap(headb);
	ft_printf("%s", "ss\n");
}
