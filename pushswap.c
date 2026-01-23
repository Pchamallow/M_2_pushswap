/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 19:15:53 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	is_number(char *str)
{
	int	sign_ok;
	int i;

	i = 0;
	sign_ok = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (1);
		sign_ok = valid_sign(&str[i]);
		if (sign_ok == 1)
			return (1);
		i++;
	}
	return (0);
}

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

void	b_to_a_content(t_list **a, t_list **b)
{
	while ((*b)->content < (*a)->content)
		push(b, a, 'a');
	if ((*b)->content == ft_max(*b) && (*b)->content < ft_lstlast(*a)->content)
	{
		reverse_rotate(a, 'a');
		push(b, a, 'a');
		while ((*a)->content != ft_min(*a))
			reverse_rotate(a, 'a');
	}
}

void	sort_four(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push(a, b, 'b');
	while (!is_sorted(a))
		sort_three(a);
	print_step(*a, "sort three");
	push(b, a, 'a');
}

void	sort_five(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push(a, b, 'b');
	while (!is_sorted(a))
		sort_three(a);
	print_step(*a, "sort three");
	b_to_a_content(a, b);
}

void sort_two_to_five(t_list **a, t_list **b)
{
    if (ft_lstsize(*a)== 2 && (*a)->content > (*a)->next->content)
        swap(a, 'a');
    else if (ft_lstsize(*a) == 3)
        sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	// {
	// 	while (ft_lstsize(*a) > 3)
	// 		push(a, b, 'b');
	// 	while (!is_sorted(a))
	// 		sort_three(a);
	// 	print_step(*a, "sort three");
	// 	// b_to_a_index(a, b);
	// 	b_to_a_content(a, b);
	// }
}

void	algorithm(t_list **a, t_list **b)
{
	fill_index(*a);
	if (ft_lstsize(*a) <= 5)
	    sort_two_to_five(a, b);
	else
		apply_butterfly(a, b);
	print_step(*a, "Result : ");
	if (is_sorted(a))
		ft_printf("\nSORTED\n\n");
	ft_lstclear(a);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
	if (argv[1] == NULL)
		return (0);
	if (is_number(argv[1]) == 1 || ft_atol(argv[1]) >= INT_MAX || ft_atol(argv[1]) <= INT_MIN || parse(argc, argv, &a) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (is_sorted(&a) == 1)
	{
		ft_lstclear(&a);
		return (0);
	}
	else
		algorithm(&a, &b);
    return (0);
}
