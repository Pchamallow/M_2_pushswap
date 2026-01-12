/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:14:17 by pswirgie          #+#    #+#             */
/*   Updated: 2025/11/08 19:39:33 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *ne)
{
	t_list	*last;

	if (!lst || !ne)
		return ;
	if (!*lst)
	{
		*lst = ne;
		return ;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = ne;
	}
	return ;
}
