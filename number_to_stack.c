/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:47:15 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/19 16:48:37 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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


int	is_int_minmax(char *numstr)
{
	if (ft_atol(numstr) > 2147483647 || ft_atol(numstr) < -2147483648)
	{
		free(numstr);
		return (1);
	}
	return (0);
}

int extract_numbers(char *str, t_list **head)
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
			if (is_int_minmax(numstr) == 1)
				return (1);
			createstacka(head, ft_atol(numstr));
			// ft_printf("%d", (*head)->content);
            free(numstr);
        }
    }
	return (0);
}

int number_to_stack( char **argv, t_list **head)
{
	int index;

	index = 1;
    while (argv[index])
    {
		if (extract_numbers(argv[index], head) == 1)
			return (1);
        index++;
    }
    return (0);
}