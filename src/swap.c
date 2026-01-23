/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:28:19 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 22:33:28 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

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

void	swapab(t_list **heada, t_list **headb)
{
	swap(heada, 'c');
	swap(headb, 'c');
	ft_printf("%s", "ss\n");
}
