/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 13:01:26 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/12 19:28:05 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

/*
Theorie 1 :
1. mettre les chiffres dans une str avec un strjoin avec des espaces entre chaque nombre
2. stack_a convertir la str en stack
3. stack_b trier la stack
*/


typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//SOURCE
void	ft_stacka(int argv);


//LIBFT
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *ne);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *ne);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
