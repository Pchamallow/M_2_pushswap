/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:48:11 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 21:49:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **source, t_list **target, char c)
{
	t_list	*tmp;

	if (*source == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *target;
	*target = *source;
	*source = tmp;
	if (c == 'a')
		ft_printf("%s\n", "pa");
	if (c == 'b')
		ft_printf("%s\n", "pb");
}

void	swap(t_list **head, char c)
{
	t_list	*tmp;

	if (!*head || !((*head)->next))
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	if (c == 'a')
		ft_printf("%s", "sa\n");
	if (c == 'b')
		ft_printf("%s", "sb\n");
	return ;
}
