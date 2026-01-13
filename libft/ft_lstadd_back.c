/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:14:17 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/12 22:44:28 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **head, t_list *newer)
{
	t_list	*last;

	last = *head;
	if (!head || !newer)
		return ;
	if (!*head)
	{
		*head = newer;
		return ;
	}
	else
	{
		last = ft_lstlast(*head);
		last->next = newer;
		newer->prev = last;
	}
	return ;
}
