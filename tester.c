/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/22 07:25:32 by pswirgie         ###   ########.fr       */
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

void	push(t_list **source, t_list **target)
{
	t_list *tmp;

    if (*source == NULL)
        return;

    tmp = *source;
    *source = (*source)->next;
    tmp->next = *target;
    *target = tmp;       
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

// create stack a
int	createstacka(t_list **head, long number)
{
	t_list	*new;

	new = ft_lstnew(number);
	if (!new)
		return (1);
	ft_lstadd_back(head, new);
	return (0);
}

