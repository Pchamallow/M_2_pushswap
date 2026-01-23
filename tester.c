/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:31:32 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 20:54:35 by pswirgie         ###   ########.fr       */
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
void    print_step(t_list *head, char *str)
{
	ft_printf("%s\n", str);
	printlist(head);
}

void	push(t_list **source, t_list **target, char c)
{
	t_list *tmp;

    if (*source == NULL)
        return;
    tmp = (*source)->next;
    (*source)->next = *target;
    *target = *source;
	*source = tmp;
	if (c == 'a')
		ft_printf("%s\n", "pa");
	if (c == 'b')
		ft_printf("%s\n", "pb");
}


// create stack a
int	createstacka(t_list **head, long number)
{
	t_list	*new;

	// if (number == 0)
	// 	return(0);
	new = ft_lstnew(number);
	if (!new)
		return (1);
	ft_lstadd_back(head, new);
	return (0);
}

