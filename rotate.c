/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:37:05 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 13:23:40 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

///////////////////////////     ROTATE     ///////////////////////////////////////////////////////////
// Shift up all elements of stack a by 1. The first element becomes the last one.
void rotate(t_list **stack, char c)
{
    t_list *head;
    t_list *tail;

    if (!stack || !*stack || !(*stack)->next)
        return;
    head = *stack;
    tail = *stack;
    while (tail->next)
        tail = tail->next;
    *stack = head->next;
    head->next = NULL;
    tail->next = head;
    if (c == 'a')
        ft_printf("ra\n");
    else if (c == 'b')
        ft_printf("rb\n");
}


// void    apply_rr(t_list **head_a, t_list **head_b, int nbr)
// {
// 	int index_a;
//     int target;

// 	index_a = find_index(*head_a, nbr);
// 	target = target_index(*head_b, nbr);
// 	while (index_a > 0 && target > 0)
//     {
//         rotate(head_a, 'c'); 
// 		rotate(head_b, 'c');
// 		ft_printf("%s", "rr\n");
// 		index_a--; 
// 		target--;  // rotations simultanées
//     }
//     while (index_a > 0)
// 	{
// 		rotate(head_a, 'a');
// 		index_a--;
// 	}
//     while (target > 0)
// 	{
// 		rotate(head_b, 'b');
// 		target--;
// 	}
// 	// push(head_a, head_b);
// }

