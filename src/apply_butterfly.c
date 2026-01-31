/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_butterfly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:54:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/31 18:10:41 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	index_insert(t_list *a, int nbr)
{
	t_list	*tmp;
	int		index;

	index = 0;
	if (nbr < ft_min(a) || nbr > ft_max(a))
	{
		tmp = a;
		while (tmp)
		{
			if (tmp->content == ft_min(a))
				return (index);
			tmp = tmp->next;
			index++;
		}
	}
	tmp = a;
	index = 0;
	while (tmp->next)
	{
		if (tmp->content < nbr && nbr < tmp->next->content)
			return (index + 1);
		tmp = tmp->next;
		index++;
	}
	return (index);
}

void	b_to_a_content(t_list **a, t_list **b)
{
	int	insert;
	int	size;

	insert = index_insert(*a, (*b)->content);
	size = ft_lstsize(*a);
	if (!b || !*b)
		return ;
	else if (insert <= size / 2)
	{
		while (insert-- > 0)
			rotate(a, 'a');
	}
	else
	{
		insert = size - insert;
		if (!((*b)->content < (*a)->content
				&& (*b)->content > ft_lstlast(*a)->content))
		{
			while (insert-- > 0)
				reverse_rotate(a, 'a');
		}
	}
	push(b, a, 'a');
}

void	b_to_a_index(t_list **a, t_list **b)
{
	int	index_max;
	int	size;

	while (*b)
	{
		size = ft_lstsize(*b);
		index_max = max_index(*b);
		if (index_max <= size / 2)
		{
			while (index_max--)
				rotate(b, 'b');
		}
		else
		{
			index_max = size - index_max;
			while (index_max--)
				reverse_rotate(b, 'b');
		}
		push(b, a, 'a');
	}
}

void	apply_butterfly(t_list **a, t_list **b)
{
	int	counter;
	int	chunk;

	counter = 0;
	chunk = ft_lstsize(*a) / 23 + 5;
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			counter++;
		}
		else if ((*a)->index <= counter + chunk)
		{
			push(a, b, 'b');
			counter++;
		}
		else
			rotate(a, 'a');
	}
	b_to_a_index(a, b);
}
