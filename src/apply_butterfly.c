/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:54:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 18:06:43 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
