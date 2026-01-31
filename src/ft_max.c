/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:58:46 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/31 17:23:44 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_min(t_list *head)
{
	int	i;

	i = head->content;
	while (head)
	{
		if (i > head->content)
			i = head->content;
		head = head->next;
	}
	return (i);
}

int	ft_max(t_list *head)
{
	int	i;

	i = head->content;
	while (head != NULL)
	{
		if (i < head->content)
			i = head->content;
		head = head->next;
	}
	return (i);
}
