/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/31 15:31:33 by pswirgie         ###   ########.fr       */
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
