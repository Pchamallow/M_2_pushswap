/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:48:11 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 17:06:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_list **source, t_list **target, char c)
{
	t_list	*tmp;

	if (*source == NULL)
		return ;
	tmp = (*source)->next;
	(*source)->next = *target;
	*target = *source;
	*source = tmp;
	if (c == 'a')
		ft_printf("%s\n", "pa");
	if (c == 'b')
		ft_printf("%s\n", "pb");
}
