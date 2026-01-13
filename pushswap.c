/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/13 02:51:19 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	// int		i;
	t_list *head;

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
	///////// CREATE ////////
	head = (t_list *)malloc(sizeof(t_list ));
	if (ft_createstacka(&head) == 1)
		printerror();
	/////// PRINT 2ND LINK ////////
	if (!head || !head->next)
    {
        printf("La liste n'a pas de 2e élément\n");
        return (1);
    }
	tester(&head);
	return (0);
}
