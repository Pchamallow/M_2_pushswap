/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 22:31:34 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/12 22:32:27 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif
