/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:55:53 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/31 18:11:11 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_little_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		swap(a, 'a');
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) >= 4)
		sort_four_to_five(a, b);
}

void	sort_three(t_list **a)
{
	if (ft_min(*a) == (*a)->content)
	{
		reverse_rotate(a, 'a');
		swap(a, 'a');
	}
	else if (ft_max(*a) == (*a)->content)
	{
		rotate(a, 'a');
		if (!is_sorted(a))
			swap(a, 'a');
	}
	else if (find_index(*a, ft_max(*a)) == 1)
		reverse_rotate(a, 'a');
	else
		swap(a, 'a');
}

void	rotate_min_a(t_list **a)
{
	int	index_min;

	index_min = find_index(*a, ft_min(*a));
	if (index_min <= ft_lstsize(*a) / 2)
	{
		while (index_min--)
			rotate(a, 'a');
	}
	else
	{
		index_min = index_min - (ft_lstsize(*a) / 2);
		while (index_min--)
			reverse_rotate(a, 'a');
		if ((*a)->content == ft_max(*a))
			rotate(a, 'a');
		if (ft_lstlast(*a)->content == ft_min(*a))
			reverse_rotate(a, 'a');
	}
}

void	sort_four_to_five(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push(a, b, 'b');
	while (!is_sorted(a))
		sort_three(a);
	while (*b)
		b_to_a_content(a, b);
	rotate_min_a(a);
}

void	algorithm(t_list **a, t_list **b)
{
	fill_index(*a);
	if (ft_lstsize(*a) <= 5)
		sort_little_stack(a, b);
	else
		apply_butterfly(a, b);
	ft_lstclear(a);
}
