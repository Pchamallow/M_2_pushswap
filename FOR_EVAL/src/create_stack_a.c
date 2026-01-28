/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 21:46:06 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	clearlist(t_list **head)
{
	t_list	*current;
	t_list	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

int	create_stack_a(t_list **a, long number)
{
	t_list	*new;

	new = ft_lstnew(number);
	if (!new)
		return (1);
	ft_lstadd_back(a, new);
	return (0);
}
