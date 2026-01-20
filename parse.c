/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:35:39 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/20 00:39:18 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "pushswap.h"
#include "libft/libft.h"
#include <stdlib.h>

// void	printerror(void)
// {
// 	ft_printf("%s\n", "Error");
// }

int	isalphabet(char **arguments)
{
	int	index;
	int i;

	index = 1;
	if (!arguments)
		return (1);
	while (arguments[index])
	{
		i = 0;
		while (arguments[index][i])
		{
			if (ft_isalpha(arguments[index][i]))
				return (1);
			i++;
		}
		index++;
	}
	return (0);
}

void	clearlist(t_list **head)
{
    t_list *current = *head;
    t_list *next;
    
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
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

int	valid_sign(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
	}
	return (0);
}

/************** PARSING ********************/
// error if : isalphabet, INT_max/INT_min, already_sort, double number)
int	parse(char **argv, t_list **heada)
{
	int	in_stack = 0;
	
	in_stack = number_to_stack(argv, heada);
	if (!argv || !argv[2] || isalphabet(argv) == 1)
		return (1);
	if (in_stack == 1 || is_duplicated(heada) == 1)
	{
		ft_lstclear(heada);
		return (1);
	}
	if (is_sorted(heada))
		return (0);
	printlist(*heada);
	return (0);
}

