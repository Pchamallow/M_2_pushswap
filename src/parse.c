/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:35:39 by pswirgie          #+#    #+#             */
/*   Updated: 2026/02/01 14:25:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	digit_or_space(char **str)
{
	int	index;
	int	i;

	index = 1;
	if (!str)
		return (1);
	while (str[index])
	{
		i = 0;
		if (str[index][i] == '\0')
			return (1);
		while (str[index][i])
		{
			if (!(str[index][i] >= '0' && str[index][i] <= '9')
				&& str[index][i] != ' ' && str[index][i] != '+'
				&& str[index][i] != '-')
				return (1);
			i++;
		}
		index++;
	}
	return (0);
}

int	is_sorted(t_list **head)
{
	t_list	*current;
	int		to_sort;

	current = *head;
	to_sort = 0;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			to_sort = 1;
		current = current->next;
	}
	if (to_sort == 0)
		return (1);
	return (0);
}

int	is_duplicated(t_list **head)
{
	t_list	*number;
	t_list	*current;

	number = *head;
	while (number != NULL)
	{
		current = number->next;
		while (current != NULL)
		{
			if (current->content == number->content)
				return (1);
			current = current->next;
		}
		number = number->next;
	}
	return (0);
}

/*Before sign : not a digit, after: is a digit */
int	valid_sign(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i - 1] >= '0' && str[i - 1] <= '9')
			return (1);
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
	}
	return (0);
}

/************** PARSING ********************/
// error if : isalphabet, > INT_max/INT_min, already_sort, double number)
int	parse(int argc, char **argv, t_list **a)
{
	int	in_stack;
	int	error;

	in_stack = 0;
	error = 0;
	error = digit_or_space(argv);
	if (!argv || error == 1)
		return (1);
	in_stack = number_to_stack(argc, argv, a);
	if (in_stack == 1 || is_duplicated(a) == 1)
	{
		ft_lstclear(a);
		return (1);
	}
	return (0);
}
