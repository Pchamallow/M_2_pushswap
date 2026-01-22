/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 18:37:05 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/22 07:16:03 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

///////////////////////////     ROTATE     ///////////////////////////////////////////////////////////
// Shift up all elements of stack a by 1. The first element becomes the last one.
void	rotate(t_list	**head, char c)
{
	t_list	*first = *head;
	t_list	*newfirst = (*head)->next;
	t_list	*last = (*head)->next;

	last = ft_lstlast(*head);//=4
	last->next = first;//=1
	first->next = NULL;
	*head = newfirst;
	if (c == 'a')
		ft_printf("%s", "ra\n");
	if (c == 'b')
		ft_printf("%s", "rb\n");
}

void    apply_rr(t_list **head_a, t_list **head_b, int nbr)
{
	int index_a;
    int target;

	index_a = find_index(*head_a, nbr);
	target = target_index(*head_b, nbr);
	while (index_a > 0 && target > 0)
    {
        rotate(head_a, 'c'); 
		rotate(head_b, 'c');
		ft_printf("%s", "rr\n");
		index_a--; 
		target--;  // rotations simultanées
    }
    while (index_a > 0)
	{
		rotate(head_a, 'a');
		index_a--;
	}
    while (target > 0)
	{
		rotate(head_b, 'b');
		target--;
	}
}

