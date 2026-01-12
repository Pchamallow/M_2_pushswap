/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstka.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:26:51 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/12 23:22:12 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "libft/libft.h"

void	ft_fillstka(t_list **head, char *nb)
{
	// t_list	add;
	t_list	*number;

	number = ft_lstnew(0);
	number->content = ft_atoi(nb);
	ft_lstadd_back(head, number);
	return ;
}
