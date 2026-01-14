/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:37:05 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/14 18:37:32 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

///////////////////////////     ROTATE     ///////////////////////////////////////////////////////////
// Shift up all elements of stack a by 1. The first element becomes the last one.
void	rotate(t_list	**head)
{
	t_list	*first = *head;
	t_list	*newfirst = (*head)->next;
	t_list	*last = (*head)->next;

	last = ft_lstlast(*head);//=4
	last->next = first;//=1
	first->next = NULL;
	*head = newfirst;
}

void rotatea(t_list **head)
{
	rotate(head);
	ft_printf("%s", "ra\n");
}

void rotateb(t_list **head)
{
	rotate(head);
	ft_printf("%s", "rb\n");
}