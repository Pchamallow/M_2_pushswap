/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:55:59 by pswirgie          #+#    #+#             */
/*   Updated: 2025/11/07 19:14:11 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;

	if ((nmemb * size) > ((size_t)-1))
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (nmemb * size));
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, (nmemb * size));
	return (tab);
}
