/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:35:39 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/17 17:10:12 by pswirgie         ###   ########.fr       */
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

int	is_already_sort(t_list **head)
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


int	give_index(char *str, int i)
{
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] != ' ' && str[i] != '\t' && str[i] != '"')
	{
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '"'))
		{
			i++;
		}
		return (i);
	}
	return (i);
}

void extract_numbers(char *str, t_list **head)
{
    int i = 0;
    int start;
    char *numstr;
    
	i = 0;
    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '"')
            i++;
        if (str[i] == '\0')
            break;
        start = i;
		if (give_index(str, i) != i)
        {
			i = give_index(str, i);
			numstr = ft_substr(str, start, i - start);
			createstacka(head, ft_atoi(numstr));
            free(numstr);
        }
    }
}

int number_to_stack( char **argv, t_list **head)
{
	int index = 1;
    
    while (argv[index])
    {
		extract_numbers(argv[index], head);
        index++;
    }
    return (0);
}

// void	alreadysorting()
// {
	
// }

// int	strargs(char **argv)
// {
// 	int		index;
// 	int		i;
// 	int		length;
// 	char	*arguments;

// 	index = 0;
// 	i = 0;
// 	arguments = NULL;
// 	while (!argv[index])
// 	{
// 		if (!arguments)
// 			arguments = malloc(sizeof(char *));
// 		while (!argv[index][i])
// 		{
// 			arguments = ft_strjoin(arguments, argv[i]);
// 			i++;
// 		}
// 		i = 0;
// 		index++;
// 	}
// 	if (isalphabet(arguments) == 1)
// 		return (1);
// 	length = ft_strlen(arguments);
// 	return (length);
// }

/************** PARSING ********************/
// error if : isascii, (put in stack puis regarder)double et INT max (avoir les digits en long), deja ranger
int	parse(char **argv, t_list *heada)
{
	// int	error;

	// error = 0;
	if (!argv || !argv[2] || isalphabet(argv) == 1)
		return (1);
	else
	{
		number_to_stack(argv, &heada);
		if (is_already_sort(&heada) == 1)
			return (1);
		printlist(heada);
	}
	return (0);
}




