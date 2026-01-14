/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/14 14:57:59 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

void	printlist(t_list *head)
{
	t_list *current = head;

	while (current != NULL)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
}

/////////////////////////// STACK A ///////////////////////////////////////////////////////////
// SWAP   2nd become 1st
void swapa(t_list **head)
{
    t_list *first = *head;
    t_list *second = (*head)->next;
    t_list *third = (*head)->next->next;

    second->next = first;
    first->next = third;
    *head = second;
	ft_printf("%s", "sa\n");
	return ;
}

// ROTATE    Shift up all elements of stack a by 1. The first element becomes the last one.
void	rotatea(t_list	**head)
{
	t_list	*first = *head;
	t_list	*newfirst = (*head)->next;
	t_list	*last = (*head)->next;

	last = ft_lstlast(*head);//=4
	last->next = first;//=1
	first->next = NULL;
	*head = newfirst;
	ft_printf("%s", "ra\n");
}

void	reverserotatea(t_list	**head)
{
	t_list	*first;
	t_list	*beforelast;
	t_list	*last;

	first = *head;
	beforelast = *head;
	last = ft_lstlast(*head);
	while (beforelast->next->next != NULL)
		beforelast = beforelast->next;
	beforelast->next = NULL;
	last->next = first;
	*head = last;
	ft_printf("%s", "rra\n");
}

// void	filllist(t_list *head)
// {
// 	int	i = 0;

// 	head->content = i;
// 	while (i < 3)
// 	{
// 		head->content = i;
// 		ft_printf("%d", head->content);
// 		head = head->next;
// 		i++;
// 	}
// 	// printlist(head);
// 	return ;
// }

// create stack a
int	ft_createstacka(t_list **head)
{
	t_list	*new;
	int		i;

	i = 0;
	// CREATE
	while (i < 5)
	{
		new = ft_lstnew(i);
		// ft_printf("%d", new->content);
		if (!new)
			return (1);
		ft_lstadd_back(head, new);
		i++;
	}
	return (0);
}

void	tester(t_list **head)
{
	ft_printf("\n%s\n", "SWAP A");
	swapa(head);
	printlist(*head);

	ft_printf("\n%s\n", "ROTATE A");
	rotatea(head);
	printlist(*head);

	ft_printf("\n%s\n", "REVERSE ROTATE A");
	reverserotatea(head);
	printlist(*head);

	return ;
}
