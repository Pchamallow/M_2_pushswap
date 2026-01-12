/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/13 00:14:56 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	int		i;
	t_list	*first;
	t_list	**heada;

	(void)argc;
	i = 0;
	// first = ft_lstnew(0);
	heada = &first;
	while (argv[i] && i < 5)
	{
		// ft_fillstka(heada, *argv[i]);
		i++;
	}
	ft_printf("%s", "pa");
	return (0);
}
