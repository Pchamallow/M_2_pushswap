/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:06:00 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 18:06:57 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	max_index(t_list *b)
{
	int	max;
	int	index;
	int	i;

	max = b->index;
	index = 0;
	i = 0;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			index = i;
		}
		b = b->next;
		i++;
	}
	return (index);
}

int	find_index(t_list *head, int nbr)
{
	int	i;

	i = 0;
	while (head)
	{
		if (nbr == head->index)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}

void	put_index(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		tmp->index = find_index(stack, tmp->content);
		tmp = tmp->next;
	}
}

void	fill_index(t_list *a)
{
	t_list	*tmp;
	t_list	*current;
	int		index;

	current = a;
	while (current)
	{
		index = 0;
		tmp = a;
		while (tmp)
		{
			if (current->content > tmp->content)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
