/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:47:15 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/20 00:13:43 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	end_number(char *str, int i)
{
	//avoir le - ou + qui avec nombre derriere s affiche 
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		i++;
	}
	return (i);
	// else
	// 	i++;
	// return (i);
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

char *fill_stacka(char *str, int i, t_list **head)
{
	int start;
	int	end;
	char *numstr;

	start = i;
	if (str[i] == '-' || str[i] == '+')
		i++;
	end = end_number(str, i);
	if ((str[i] >= '0' && str[i] <= '9') && end != i && end > i)
	{
		numstr = ft_substr(str, start, (end - start));
		if (is_int_minmax(numstr) == 1)
		{
			free(numstr);
			return (NULL);
		}
		createstacka(head, ft_atol(numstr));
		// ft_printf("%d", (*head)->content);
		return(numstr);
	}
	else
		return (NULL);
}
	
int extract_numbers(char *str, t_list **head)
{
    int i;
	int sign_error;
    char *numstr;
	i = 0;

    while (str[i])
    {
        while (!(str[i] >= '0' && str[i] <= '9') && str[i] != '+' && str[i] != '-' && str[i] != '\0')
            i++;
        if (str[i] == '\0')
            return (0);
		sign_error = valid_sign(&str[i]);
		if (sign_error == 1)
			return (1);
		numstr = fill_stacka(str, i, head);
		if (numstr == NULL)
			return (1);
		else
		{
			i = i + ft_strlen(numstr);
			free(numstr);
		}
    }
	return (0);
}

int number_to_stack( char **argv, t_list **head)
{
	int index;
	int	error;

	index = 1;
    while (argv[index])
    {
		error = extract_numbers(argv[index], head);
		if (error == 1)
			return (1);
        index++;
    }
    return (0);
}