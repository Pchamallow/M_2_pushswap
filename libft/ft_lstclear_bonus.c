/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:14:24 by pswirgie          #+#    #+#             */
/*   Updated: 2025/11/07 14:25:51 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !del)
		return ;
	tmp = *lst;
	tmp2 = NULL;
	while (tmp)
	{
		tmp2 = tmp;
		del(tmp->content);
		tmp = tmp->next;
		free(tmp2);
	}
	*lst = tmp;
	return ;
}
