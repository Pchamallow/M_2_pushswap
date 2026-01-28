/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:31:50 by pswirgie          #+#    #+#             */
/*   Updated: 2025/11/09 17:19:25 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destb;
	unsigned char	*srcb;

	i = 0;
	destb = (unsigned char *)dest;
	srcb = (unsigned char *)src;
	while (n > 0)
	{
		destb[i] = srcb[i];
		n--;
		i++;
	}
	return (dest);
}
