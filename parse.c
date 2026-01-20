/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:35:39 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/20 04:05:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "pushswap.h"
#include "libft/libft.h"
#include <stdlib.h>

void	printerror(void)
{
	ft_printf("%s\n", "Error");
}

int	digit_or_space(char **str, int argc)
{
	int	index;
	int i;

	(void)argc;
	index = 1;
	if (!str)
		return (1);
	while (str[index])
	{
		i = 0;
		if(str[index][i] == '\0')
			return (1);
		while (str[index][i])
		{
			if (!(str[index][i] >= '0' && str[index][i] <= '9') && str[index][i] != ' ' && str[index][i] != '+' && str[index][i] != '-')
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
/*sign = before: not a digit  after: a digit */
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
// error if : isalphabet, INT_max/INT_min, already_sort, double number)
int	parse(int argc, char **argv, t_list **heada)
{
	int	in_stack = 0;
	int error = 0;
	
	error = digit_or_space(argv, argc);
	if (!argv || error == 1)
		return (1);
	in_stack = number_to_stack(argc, argv, heada);
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

