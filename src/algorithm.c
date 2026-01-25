/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:55:53 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 17:59:17 by pswirgie         ###   ########.fr       */
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

void	sort_three(t_list **head)
{
	if (ft_min(*head) == (*head)->content)
	{
		reverse_rotate(head, 'a');
		swap(head, 'a');
	}
	else if (ft_max(*head) == (*head)->content)
	{
		rotate(head, 'a');
		if (!is_sorted(head))
			swap(head, 'a');
	}
	else if (find_index(*head, ft_max(*head)) == 1)
		reverse_rotate(head, 'a');
	else
		swap(head, 'a');
}

void	sort_four_to_five(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push(a, b, 'b');
	while (!is_sorted(a))
		sort_three(a);
	while (*b)
		b_to_a_content(a, b);
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
