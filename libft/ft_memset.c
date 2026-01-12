/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:46:00 by pswirgie          #+#    #+#             */
/*   Updated: 2025/10/22 12:15:33 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char *)s;
	while (n > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
		n--;
	}
	return (s);
}
