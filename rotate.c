/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:37:05 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/20 00:47:17 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

///////////////////////////     ROTATE     ///////////////////////////////////////////////////////////
// Shift up all elements of stack a by 1. The first element becomes the last one.
void	rotate(t_list	**head, char c)
{
	t_list	*first = *head;
	t_list	*newfirst = (*head)->next;
	t_list	*last = (*head)->next;

	last = ft_lstlast(*head);//=4
	last->next = first;//=1
	first->next = NULL;
	*head = newfirst;
	if (c == 'a')
		ft_printf("%s", "ra\n");
	if (c == 'b')
		ft_printf("%s", "rb\n");
}

void    rotateab(t_list **heada, t_list **headb)
{
	rotate(heada, 'c');
	rotate(headb, 'c');
	ft_printf("%s", "rr\n");
}