/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:14:24 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/15 18:00:14 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **head, void (*del)(int))
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
