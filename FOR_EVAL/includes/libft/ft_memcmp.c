/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:27:24 by pswirgie          #+#    #+#             */
/*   Updated: 2025/11/09 10:13:54 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = (unsigned char *) s1;
	src2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((src1[i] == src2[i]) && i < n - 1)
	{
		i++;
	}
	return (src1[i] - src2[i]);
}
