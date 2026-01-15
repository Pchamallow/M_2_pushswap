/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/15 17:28:21 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
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

//Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.

void	push(t_list **source, t_list **target)
{
	t_list *first = *source;
	t_list	*oldfirst = *target;

	if (!source)
		return ;
	first->next = oldfirst;
	*target = first;
}
void	pusha(t_list **heada, t_list **headb)
{
	push(headb, heada);
	ft_printf("%s\n", "pa");
}

void	pushb(t_list **heada, t_list **headb)
{
	push(heada, headb);
	ft_printf("%s\n", "pb");
}


int	ft_free(char *tab)
{
	int	i = 0;

	if (!tab)
		return (1);
	while (tab[i])
	{
		free(tab);
		i++;
	}
	return (0);
}



// void	fillstacka(long number, t_list *head)
// {
// 	(void)head;
// 	number = 4;
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
		if (!new)
			return (1);
		ft_lstadd_back(head, new);
		i++;
	}
	return (0);
}

int	ft_createstackb(t_list **head)
{
	t_list	*new;
	int		i;

	i = 0;
	// CREATE
	while (i < 5)
	{
		new = ft_lstnew(1);
		if (!new)
			return (1);
		ft_lstadd_back(head, new);
		i++;
	}
	return (0);
}

void	tester(t_list **heada, t_list **headb)
{
	////////////////////// PRINT STACKS /////////////////////////////////
	ft_printf("\n%s\n", "STACK A");
	printlist(*heada);
	ft_printf("\n%s\n", "STACK B");
	printlist(*headb);

	// ////////////////////// MOVES STACK A /////////////////////////////////
	ft_printf("\n%s\n", "PUSH");
	pushb(heada, headb);
	printlist(*heada);
	
	// ft_printf("\n%s\n", "ROTATE A");
	// rotatea(heada);
	// printlist(*heada);

	// ft_printf("\n%s\n", "REVERSE ROTATE A");
	// reverserotatea(heada);
	// printlist(*heada);




	return ;
}
