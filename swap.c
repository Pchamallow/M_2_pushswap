/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/13 15:07:41 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"


// stack a : le 2e devient 1er
void	swapa(t_list **heada)
{
	t_list	*newer;

	newer = (*heada)->next->content;
	ft_lstadd_front(heada, newer);
	ft_printf("%s", "sa");
}

t_list	**ft_createstacka()
{
	t_list	**head;
	t_list	*new;
	int		i = 0;

	new = NULL;
	head = &new;
	// (**head).content = new;
	while (i < 3)
	{
		new = ft_lstnew(0);
		ft_lstadd_back(head, new);
		i++;
	}
	return (head);
}

void	tester(t_list **head)
{
	swapa(head);
	return ;
}
