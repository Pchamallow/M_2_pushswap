/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 04:37:06 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 04:25:52 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "ft_printf/ft_printf.h"

int     ft_min(t_list *head)
{
    int i;

    i = head->content;
    while (head)
    {
        if (i > head->content)
        i = head->content;
        head = head->next;
    }
    // ft_printf("min = %d\n", i);
    return (i);
}

int     ft_max(t_list *head)
{
    int i;

    i = head->content;
    while (head)
    {
        if (i < head->content)
            i = head->content;
        head = head->next;
    }
    // ft_printf("max = %d\n", i);
    return (i);
}

int find_index(t_list *head, int nbr)
{
    int i;

    i = 0;
    while (head)
    {
        if (nbr == head->content)
            return (i);
        head = head->next;
        i++;
    }
    return (-1);
}

void    sort_three(t_list **head)
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

// int target_index_a(t_list *head_a, int nbr_a)
// {
//     t_list  *current;
//     int     i;

//     i = 0;
//     if (nbr_a > head_a->content && nbr_a < ft_lstlast(head_a)->content)
//         i = 0;
//     else if (nbr_a > ft_max(head_a) || nbr_a < ft_min(head_a))
//         i = find_index(head_a, ft_max(head_a));
//     else
// 	{
// 		current = head_a->next;
// 		while (nbr_a > head_a->content || nbr_a < current->content)
// 		{
// 			head_a = head_a->next;
// 			current = head_a->next;
// 			i++;
// 		}
// 	}
// 	return (i);
// }

int target_index(t_list *head, int nbr)
{
    t_list  *current;
    int     i;

    i = 0;
    if (nbr > head->content && nbr < (ft_lstlast(head))->content)
        i = 0;
    else if (nbr > ft_max(head) || nbr < ft_min(head))
        i = find_index(head, ft_max(head));
    else
	{
		current = head->next;
		while (nbr > head->content || nbr < current->content)
		{
			head = head->next;
			current = head->next;
			i++;
		}
	}
	return (i);
}

int cost(int len, int index, int reverse)
{
    int cost;

    if (reverse)
        cost = len - index;
    else
        cost = index;
    return (cost);
}

int better_case(t_list *head_a, t_list *head_b, int nbr)
{
    int rarrb;
    int rrr;
    int rrarb;
    int min_cost;

    min_cost = case_rarb(head_a, head_b, nbr);
    rarrb = case_rarrb(head_a, head_b, nbr);
    rrr = case_rrr(head_a, head_b, nbr);
    rrarb = case_rrarb(head_a, head_b, nbr);
    if (rarrb < min_cost)
        min_cost = rarrb;
    if (rrr < min_cost)
        min_cost = rrr;
    if (rrarb < min_cost)
        min_cost = rrarb;

    return (min_cost);
}

int nbr_less_cost(t_list *head_a, t_list *head_b)
{
    t_list  *current;
    t_list  *best;
    int     cost;
    int     best_cost;
    
    
    current = head_a;
    best_cost = case_rarb(head_a, head_b, current->content);
    best = ft_lstnew(current->content);
    // ft_printf("%d", ft_lstsize(head_a));
    // ft_printf("%d", ft_lstsize(current));
    ft_printf("search nbr_less_cost\n");
    while (current)
    {
        cost = better_case(head_a, head_b, current->content);
        if (cost < best_cost)
        {
            best_cost = cost;
            best->content = current->content;// ou mettre un index i opour savoir ou est l elelemnet ?
        }
        current = current->next;
    }
    return (best->content);
}


//appliquer le nbr avec le moindre cout puis le push
void put_best(t_list **head_a, t_list **head_b, int nbr)
{
    int index_a;
    int target;
    int len_a;
    int len_b;
    
    len_a = ft_lstsize(*head_a);
    len_b = ft_lstsize(*head_b);
    index_a = find_index(*head_a, nbr);
	target = target_index(*head_b, nbr);
    if (index_a <= len_a/2 && target <= len_b/2)
        apply_rr(head_a, head_b, nbr);
    else if (index_a <= len_a/2 && target > len_b/2)
        apply_rarrb(head_a, head_b, nbr);
    else if (index_a > len_a/2 && target > len_b/2)
        apply_rrarrb(head_a, head_b, nbr);
    else
        apply_rrarb(head_a, head_b, nbr);

}

void    print_step(t_list *head, char *str)
{
    ft_printf("\n%s\n", str);
    printlist(head);
}

// void b_to_empty(t_list **head_a, t_list **head_b)
// {
//     int best;

//     best = nbr_less_cost(*head_a, *head_b);
//     put_best(head_a, head_b, best);
// }

void sort_two_to_five(t_list **head_a, t_list **head_b)
{
    int len_a;
    // int i = 0;
    
    len_a = ft_lstsize(*head_a);
    if (len_a == 2 && (*head_a)->content > (*head_a)->next->content)
        swap(head_a, 'a');
    else if (len_a == 3)
        sort_three(head_a);
    else
    {
        while (ft_lstsize(*head_a) > 3)
        {
            if (find_index(*head_a, ft_min(*head_a)) == 0)
            {
                pushb(head_a, head_b);
                print_step(*head_a, "step pushb :");
            }
            else if (find_index(*head_a, ft_min(*head_a)) <= ft_lstsize(*head_a)/2)
            {
                rotate(head_a, 'a');
                print_step(*head_a, "step rotate :");
            }
            else
            {
                reverse_rotate(head_a, 'a');
                print_step(*head_a, "step rr :");
            }
        }
        // if (!is_sorted(head_a))
        // {
        //     sort_three(head_a);
        //     print_step(*head_a, "step sort_three :");
        // }
        // while (is_sorted(head_a) && i < ft_lstsize(*head_b))
        // {
        //     b_to_empty(head_a, head_b);
        //     i++;
        //     // best = nbr_less_cost(*head_a, *head_b);
        //     // put_best(head_a, head_b, best);
        // }
        // while (ft_lstsize(*head_b) > 0)
        //     pusha(head_a, head_b);
    }
}

void    sort_nbr(t_list **head_a, t_list **head_b)
{
    int best;
    int len_b;
    int i = 0;

    len_b = ft_lstsize(*head_b);
    print_step(*head_b, "\nBefore sort_nbr :");
    while (i < len_b)
    {
        best = nbr_less_cost(*head_a, *head_b);
        put_best(head_a, head_b, best);
        i++;
    }
}

// verifier si je dois creer la  stack b meme si la len est de 2 ou pas
void    algo(t_list **head_a)
{
    t_list  *head_b;
    
    head_b = NULL;
    print_step(*head_a, "original :");
    ft_printf("\n");
    while (ft_lstsize(*head_a) > 5)
        pushb(head_a, &head_b);
    if (ft_lstsize(*head_a) <= 5)
        sort_two_to_five(head_a, &head_b);
    // if (head_b)
    // {
    sort_nbr(head_a, &head_b);
    // }
    // ft_printf("index : %d\n", find_index(head_b, (*head_a)->content));
    if (is_sorted(head_a) == 1)
        ft_printf("sorted\n");
}
