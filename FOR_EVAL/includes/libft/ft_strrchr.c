/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:03:23 by pswirgie          #+#    #+#             */
/*   Updated: 2025/10/25 17:32:48 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*a;
	char	to_find;

	j = 0;
	i = ft_strlen(s);
	a = (char *)s;
	to_find = (char) c;
	while (i >= j)
	{
		if (a[i] == to_find)
			return (&a[i]);
		i--;
	}
	return (NULL);
}
