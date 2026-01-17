/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/17 17:11:24 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	// int		i = 1;
	t_list *heada = NULL;
	// t_list *headb;

	//PARSING/////////////////////////////////
	if (argc <= 2 || parse(argv, heada) == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	// (void)argv;
	else
	{
		return (0);
	}
	// PRINT ARGV //
	// ft_printf("\n%s\n", "ARGV");
	// while (argv[i])
	// {
	// 	ft_printf("%s\n", argv[i]);
	// 	i++;
	// }

	///////// CREATE STACK A et B////////
	// heada = NULL;
	// headb = NULL;
	// if (ft_createstacka(&heada) == 1 || ft_createstackb(&headb))
	// 	printerror();
	// tester(&heada, &headb);
	
	// clearlist(&heada);
}

