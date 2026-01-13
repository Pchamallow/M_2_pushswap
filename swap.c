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

void	printlist(t_list *head)
{
	int i = 0;
	while (i < 3)
	{
		ft_printf("%d\n", head->next->content);
		head = head->next;
		i++;
	}
}

/////////////////////////// STACK A ///////////////////////////////////////////////////////////
// SWAP   2nd become 1st
void swapa(t_list *head)
{
	int	tmp;

	tmp = head->next->content;//= 0
	head->next->content = head->next->next->content;
	head->next->next->content = tmp;
	ft_printf("%s", "test");
	ft_printf("%d", head->next->next->next->content);
	return ;
}

// ROTATE    Shift up all elements of stack a by 1. The first element becomes the last one.
void	rotatea(t_list	*head)
{
	ft_printf("\n%s\n", "ROTATE A");
	head->next= head->next->next;
	// head = head->next->next->next;
	printlist(head);
}

void	filllist(t_list *head)
{
	int	i = 0;

	head->content = i;
	while (i < 3)
	{
		head->content = i;
		head = head->next;
		i++;
	}
	// printlist(head);
	return ;
}

// create stack a
int	ft_createstacka(t_list **head)
{
	t_list	*new;
	int		i = 0;

	// CREATE
	ft_printf("%s\n", "CREATED STACK A");
	while (i < 3)
	{
		new = ft_lstnew(i);
		if (!new)
			return (1);
		ft_printf("%d\n", new->content);
		ft_lstadd_back(head, new);
		i++;
	}
	////// FILL  /   PRINT    THE LIST //////
	// filllist(*head);
	return (0);
}

void	tester(t_list **head)
{
	ft_printf("\n%s\n", "SWAP A");
	swapa(*head);
	ft_printf("%s", "sa\n");
	printlist(*head);
	rotatea(*head);
	return ;
}
