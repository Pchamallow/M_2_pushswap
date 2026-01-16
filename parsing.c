/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:35:39 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/16 15:18:19 by pswirgie         ###   ########.fr       */
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

void	onlynumber(char **argv, t_list **head)
{
	int		index = 1;
	int		i = 0;
	// int		y = 0;
	char	*tmp = NULL;
	char	*base = (char *)malloc(sizeof(char));

	(*head)->content = 1;
	while (argv[index])
	{
		i = 0;
		while (argv[index][i])
		{
			// if (argv[index][i] == ' ' || argv[index][i] == '\n' || argv[index][i] == '\t' || argv[index][i] == '\b')  
			// {
			// 	i++;
			// 	continue;
			// }
			// ft_printf("%s\n", argv[index]);
				// if (ft_isdigit(ft_atoi("1")) == 0)
			if (ft_isdigit(argv[index][i]) == 0)			
			{
				// tmp = ft_strjoin(tmp, &argv[index][i]);
				ft_printf("%c\n", argv[index][i]);
				tmp = base;
				base = ft_strjoin(tmp, &argv[index][i]);
				free(tmp);
				// ft_printf("%c\n", tmp[y]);
				i++;
			// 	y++;
			}
			else
			{
				i++;
				continue;
			}
		}
		free(base);
		index++;
	}
	clearlist(head);
	return ;
}

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
		ft_createstacka(&heada);
		onlynumber(argv, &heada);
	}
	return (0);
}




