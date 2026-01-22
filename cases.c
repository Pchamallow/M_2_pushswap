/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:02:52 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/22 04:02:52 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int case_rarb(t_list *head_a, t_list *head_b, int nbr)
{
    int cost_a;
    int cost_b;
    int max;

    cost_a = cost(ft_lstsize(head_a), find_index(head_a, nbr), 0);
    cost_b = cost(ft_lstsize(head_b), target_index(head_b, nbr), 0);
    if (cost_a > cost_b)
        max = cost_a;
    else
        max = cost_b;
    return (max);
}

int case_rrr(t_list *head_a, t_list *head_b, int nbr)
{
    int cost_a;
    int cost_b;
    int max;

    cost_a = cost(ft_lstsize(head_a), find_index(head_a, nbr), 1);
    cost_b = cost(ft_lstsize(head_b), target_index(head_b, nbr), 1);
    if (cost_a > cost_b)
        max = cost_a;
    else
        max = cost_b;
    return (max);
}

int case_rarrb(t_list *head_a, t_list *head_b, int nbr)
{
    int cost_a;
    int cost_b;
    int total;

    cost_a = cost(ft_lstsize(head_a), find_index(head_a, nbr), 0);
    cost_b = cost(ft_lstsize(head_b), target_index(head_b, nbr), 1);
    total = cost_a + cost_b;
    return (total);
}

int case_rrarb(t_list *head_a, t_list *head_b, int nbr)
{
    int cost_a;
    int cost_b;
    int total;

    cost_a = cost(ft_lstsize(head_a), find_index(head_a, nbr), 1);
    cost_b = cost(ft_lstsize(head_b), target_index(head_b, nbr), 0);
    total = cost_a + cost_b;
    return (total);
}