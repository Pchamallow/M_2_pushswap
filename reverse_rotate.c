/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:38:08 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 09:53:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

///////////////////////////     REVERSE ROTATE     ///////////////////////////////////////////////////////////
void	reverse_rotate(t_list **head, char c)
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
	if (c == 'a')
		ft_printf("%s", "rra\n");
	if (c == 'b')
		ft_printf("%s", "rrb\n");
}

// void    apply_rrarrb(t_list **head_a, t_list **head_b, int nbr)
// {
// 	int index_a;
//     int target;
// 	int	len_a;
// 	int	len_b;

// 	index_a = find_index(*head_a, nbr);
// 	target = target_index(*head_b, nbr);
// 	len_a = ft_lstsize(*head_a);
// 	len_b = ft_lstsize(*head_b);
// 	while (index_a < len_a)
// 	{
// 		reverse_rotate(head_a, 'a');
// 		index_a++;
// 	}
//     while (target < len_b)
// 	{
// 		reverse_rotate(head_b, 'b');
// 		target++;
// 	}
// 	ft_printf("%s", "rrr\n");
// 	pusha(head_a, head_b);
// }

// void    apply_rrarb(t_list **head_a, t_list **head_b, int nbr)
// {
// 	int index_a;
//     int target;
// 	int	len_a;

// 	index_a = find_index(*head_a, nbr);
// 	target = target_index(*head_b, nbr);
// 	len_a = ft_lstsize(*head_a);
//     while (index_a < len_a)
// 	{
// 		reverse_rotate(head_a, 'a');
// 		index_a++;
// 	}
//     while (target > 0)
// 	{
// 		reverse_rotate(head_b, 'b');
// 		target--;
// 	}
// 	pusha(head_a, head_b);
// }

// void    apply_rarrb(t_list **head_a, t_list **head_b, int nbr)
// {
// 	int index_a;
//     int target;
// 	int	len_b;

// 	index_a = find_index(*head_a, nbr);
// 	target = target_index(*head_b, nbr);
// 	len_b = ft_lstsize(*head_b);
// 	while (index_a > 0)
// 	{
// 		rotate(head_a, 'a');
// 		index_a--;
// 	}
//     while (target < len_b)
// 	{
// 		reverse_rotate(head_b, 'b');
// 		target++;
// 	}
// 	pusha(head_a, head_b);
// }
