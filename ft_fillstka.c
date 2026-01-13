/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:26:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/13 02:00:33 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

// 	//parsing en checkant va regarder le nb de nombre\
// 	//algo turc ou algo papillon

// void	ft_fillstkb(t_list **head, char *nb)
// {
// 	// t_list	add;
// 	t_list	*number;
//
// 	number = ft_lstnew(0);
// 	number.content = ft_atoi(nb);
// 	ft_lstadd_back(head, number);
// 	return ;
// }
//

// void	ft_pushpa(t_list **stacka, t_list **stackb)
// {
// 	ft_lstadd_front(stacka, *stackb);
// 	ft_printf("%s", "pa");
// }

void	ft_createstack()
{
	t_list	**head;
	t_list	*new;
	int		i = 0;

	head = NULL;
	new = NULL;
	while (i < lengthlist)
	{
		new = ft_lstnew(0);
		i++;
	}
	if (!head)
		head.content = &new;
}
