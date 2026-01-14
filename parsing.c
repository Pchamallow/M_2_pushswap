/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:35:39 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/14 20:32:16 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "pushswap.h"
#include <stdlib.h>

int	printerror(void)
{
	ft_printf("%s\n", "Error");
	return (1);
}

int	isalphabet(char *arguments)
{
	int	i;

	i = 0;
	if (!arguments)
		return(1);
	while (!arguments[i])
	{
		if (ft_isascii(arguments[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	strargs(char **argv)
{
	int		index;
	int		i;
	int		length;
	char	*arguments;

	index = 0;
	i = 0;
	arguments = NULL;
	while (!argv[index])
	{
		if (!arguments)
			arguments = malloc(sizeof(char *));
		while (!argv[index][i])
		{
			arguments = ft_strjoin(arguments, argv[i]);
			i++;
		}
		i = 0;
		index++;
	}
	if (isalphabet(arguments) == 1)
		return (1);
	length = ft_strlen(arguments);
	return (length);
}

//1. argv tout en une string qui est
//2. cette string, la mettre dans tableaux, spearer des qu il y a un espace ou autre
char	*allnumbers(char **argv)
{
	ft_strjoin(argv)
}
//argv -> avoir une liste 
//argv -> simple = strjoin le tout puis detecte les espaces
//ou argv -> espace ou +/- -> atoi -> stack a
//
//
//


