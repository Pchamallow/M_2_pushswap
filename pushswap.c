/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/14 18:33:14 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	// int		i;
	t_list *heada;
	t_list *headb;

	(void)argc;
	(void)argv;

	//PARSING/////////////////////////////////
	// i = 0;
	// if (!argv || strargs(argv) == 1)
	// {
	// 	printerror();
	// 	return (1);
	// }
	// i = 0;

	///////// CREATE STACK A et B////////
	heada = NULL;
	headb = NULL;
	if (ft_createstack(&heada) == 1 || ft_createstack(&headb))
		printerror();
	tester(&heada, &headb);
	return (0);
}
