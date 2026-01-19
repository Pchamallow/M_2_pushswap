/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/19 19:49:52 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	// int		i = 1;
	t_list *heada = NULL;
	int		valid = 0;
	// t_list *headb;

	//PARSING/////////////////////////////////
	if (argc <= 2 || valid == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	valid = parse(argv, &heada);
	if (valid == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	// (void)argv;
	else
	{
		ft_lstclear(&heada);
	}
	return (0);
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

