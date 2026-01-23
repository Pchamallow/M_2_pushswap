/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 21:55:01 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"
#include "unistd.h"

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
	int	count;

	count = 0;
	if (ft_max(*a) < (*b)->content)
	{
		push(b, a, 'a');
		rotate(a, 'a');
		return ;
	}
	if (ft_min(*a) > (*b)->content)
	{
		push(b, a, 'a');
		return ;
	}
	while ((*b)->content > (*a)->content)
	{
		rotate(a, 'a');
		count++;		
	}
	push(b, a, 'a');
	while (count > 0)
	{
		reverse_rotate(a, 'a');
		count--;
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
}

void sort_little_stack(t_list **a, t_list **b)
{
    if (ft_lstsize(*a)== 2)
        swap(a, 'a');
    else if (ft_lstsize(*a) == 3)
        sort_three(a);
	else if (ft_lstsize(*a) >= 4)
		sort_four_to_five(a, b);
}

void	algorithm(t_list **a, t_list **b)
{
	fill_index(*a);
	if (ft_lstsize(*a) <= 5)
	    sort_little_stack(a, b);
	else
	{
		apply_butterfly(a, b);
		ft_lstclear(a);
	}
}
	
int	only_null(t_list *a)
{
	if (ft_lstsize(a) > 1)
	{
		while (a)
		{
			if (a->content != 0)
			return (0);
			a = a->next;	
		}
		return (1);
	}
	return (0);
}
	
int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	
	a = NULL;
	b = NULL;
	if (argv[1] == NULL) 
	return (0);
	if (is_number(argv[1]) == 1  || ft_atol(argv[1]) > INT_MAX || ft_atol(argv[1]) < INT_MIN || parse(argc, argv, &a) == 1 || only_null(a) == 1)
	{
		ft_lstclear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_lstsize(a) == 1 || is_sorted(&a) == 1)
	{
		ft_lstclear(&a);
		return (0);
	}
	else
	algorithm(&a, &b);
	return (0);
	// print_step(*a, "Result : ");
	// if (is_sorted(a))
	// 	// ft_printf("\nSORTED\n\n");
}
	