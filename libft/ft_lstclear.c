/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:14:24 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/12 19:51:53 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **head, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!head || !del)
		return ;
	tmp = *head;
	tmp2 = NULL;
	while (tmp)
	{
		tmp2 = tmp;
		del(tmp->content);
		tmp = tmp->next;
		free(tmp2);
	}
	*head = tmp;
	return ;
}
