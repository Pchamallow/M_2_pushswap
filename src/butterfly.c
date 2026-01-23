/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:54:27 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 22:00:16 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

int	max_index(t_list *b)
{
    int max;
    int index;
    int i;

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

void b_to_a_index(t_list **a, t_list **b)
{
    int index_max;
    int size;

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

void    put_index(t_list *stack)
{
    t_list *tmp;

    tmp = stack;
    while (tmp)
    {
        tmp->index = find_index(stack, tmp->content);
        tmp = tmp->next;
    }
}

void fill_index(t_list *a)
{
    t_list *tmp;
    t_list *current;
    int index;

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

void apply_butterfly(t_list **a, t_list **b)
{
    int counter;
    int chunk;

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
