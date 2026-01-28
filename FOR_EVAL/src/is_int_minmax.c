/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_minmax.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:51:56 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/25 17:51:15 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_int_minmax(char *numstr)
{
	if (ft_atol(numstr) > 2147483647 || ft_atol(numstr) < -2147483648)
	{
		free(numstr);
		return (1);
	}
	return (0);
}
