/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 17:59:32 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_number(char *str)
{
	int	sign_ok;
	int	i;

	i = 0;
	sign_ok = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9')
			&& str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (1);
		sign_ok = valid_sign(&str[i]);
		if (sign_ok == 1)
			return (1);
		i++;
	}
	return (0);
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argv[1] == NULL)
		return (0);
	if (is_number(argv[1]) == 1 || ft_atol(argv[1]) > INT_MAX
		|| ft_atol(argv[1]) < INT_MIN || parse(argc, argv, &stack_a) == 1
		|| only_null(stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_lstsize(stack_a) == 1 || is_sorted(&stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	else
		algorithm(&stack_a, &stack_b);
	return (0);
}
