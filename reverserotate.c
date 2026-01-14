/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:38:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/14 18:38:18 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

///////////////////////////     REVERSE ROTATE     ///////////////////////////////////////////////////////////
void	reverserotate(t_list	**head)
{
	t_list	*first;
	t_list	*beforelast;
	t_list	*last;

	first = *head;
	beforelast = *head;
	last = ft_lstlast(*head);
	while (beforelast->next->next != NULL)
		beforelast = beforelast->next;
	beforelast->next = NULL;
	last->next = first;
	*head = last;
}

void reverserotatea(t_list **head)
{
	rotate(head);
	ft_printf("%s", "rra\n");
}

void reverserotateb(t_list **head)
{
	rotate(head);
	ft_printf("%s", "rrb\n");
}
