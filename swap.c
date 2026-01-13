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
	t_list	*second = head->next;

	tmp = second->content;
	second->content = second->next->content;
	second->next->content = tmp;
	ft_printf("%s", "sa\n");
	return ;
}

// ROTATE    Shift up all elements of stack a by 1. The first element becomes the last one.
void	rotatea(t_list	**head)
{
	t_list	*first = *head;
	t_list	*last = *head;

	if (*head == NULL || (*head)->next == NULL) 
        return;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;//le 2e devient la tete (pas le 1er)
	first->next = NULL;//le 1er est isole
	last->next = *head;//apres le dernier pointe vers l ancien 1er
	ft_printf("%s", "ra\n");
}

void	reverserotatea(t_list	**head)
{
	t_list	*last = *head;
	t_list	*prevlast = NULL;

	if (*head == NULL || (*head)->next == NULL) 
        return;
	while (last->next != NULL)
	{
		prevlast = last;//avant dernier
		last = last->next;
	}
	prevlast->next = NULL;//prevlast dernier
	last->next = *head;//last devient premier (head etant a 0)
	*head = last;
	ft_printf("%s", "rra\n");
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
	return (0);
}

void	tester(t_list **head)
{
	int	length;

	length = 4;
	ft_printf("\n%s\n", "SWAP A");
	swapa(*head);
	printlist(*head);
	ft_printf("\n%s\n", "ROTATE A");
	rotatea(head);
	printlist(*head);
	ft_printf("\n%s\n", "REVERSE ROTATE A");
	reverserotatea(head);
	return ;
}
