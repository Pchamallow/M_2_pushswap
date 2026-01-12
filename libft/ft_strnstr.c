/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:03:15 by pswirgie          #+#    #+#             */
/*   Updated: 2025/11/09 17:20:30 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*src;

	i = 0;
	j = 0;
	if (!little)
		return ((char *)big);
	if (!big)
		return (NULL);
	src = (char *)big;
	if (little[i] == 0 || !little)
		return (src);
	while (src[i] && (i + j) < len)
	{
		if (src[i + j] == little[j])
			j++;
		else
		{
			j = 0;
			i++;
		}
		if (!little[j])
			return (&src[i]);
	}
	return (NULL);
}
