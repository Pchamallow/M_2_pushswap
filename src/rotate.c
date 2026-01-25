/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:37:05 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 17:52:14 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list **stack, char c)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
}
