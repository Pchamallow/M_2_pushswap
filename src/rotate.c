/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:37:05 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 21:49:10 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **first, char c)
{
	t_list	*head;
	t_list	*tail;

	if (!first || !*first || !(*first)->next)
		return ;
	head = *first;
	tail = *first;
	while (tail->next)
		tail = tail->next;
	*first = head->next;
	head->next = NULL;
	tail->next = head;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}

void	reverse_rotate(t_list **head, char c)
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
	if (c == 'a')
		ft_printf("%s", "rra\n");
	if (c == 'b')
		ft_printf("%s", "rrb\n");
}
