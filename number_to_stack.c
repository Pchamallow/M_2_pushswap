/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:47:15 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/19 19:21:06 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	give_index(char *str, int i)
{
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-')
	{
		while (!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-')
		{
			i++;
		}
	}
	else
		i++;
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
	int end;
    int start;
	int sign_error;
    char *numstr;
    
	i = 0;
    while (str[i])
    {
        while (!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-')
            i++;
        if (str[i] == '\0')
            break;
        start = i;
		end = give_index(str, i);
		if (end != i && end > i)
        {
			i = end;
			numstr = ft_substr(str, start, (i - start));
			sign_error = valid_sign(numstr);
			if (is_int_minmax(numstr) == 1 || sign_error == 1)
				return (1);
			createstacka(head, ft_atol(numstr));
			// ft_printf("%d", (*head)->content);
            free(numstr);
        }
		else
			return (1);
    }
	return (0);
}

int number_to_stack( char **argv, t_list **head)
{
	int index;
	int	error;

	index = 1;
	error = extract_numbers(argv[index], head);
    while (argv[index])
    {
		if (error == 1)
			return (1);
        index++;
    }
    return (0);
}