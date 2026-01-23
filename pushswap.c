/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pswirgie <pswirgie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 19:13:02 by pswirgie          #+#    #+#             */
/*   Updated: 2026/01/23 15:47:20 by pswirgie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int	is_number(char *str)
{
	int	sign_ok;
	int i;

	i = 0;
	sign_ok = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (1);
		sign_ok = valid_sign(&str[i]);
		if (sign_ok == 1)
			return (1);
		i++;
	}
	return (0);
}


// int	main(int argc, char **argv)
// {
// 	t_list *heada = NULL;
// 	t_list *headb = NULL;
// 	int		error = 0;
// 	// t_list *headb;

// 	if (argv[1] == NULL)
// 		return (0);
// 	error = is_number(argv[1]);
// 	if (error == 1 || ft_atol(argv[1]) >= INT_MAX || ft_atol(argv[1]) <= INT_MIN)
// 	{
// 		ft_printf("Error\n");
// 		return (1);
// 	}
// 	error = parse(argc, argv, &heada);
// 	if (error == 1)
// 	{
// 		ft_printf("Error\n");
// 		return (1);
// 	}
// 	else if (is_sorted(&heada) == 1)
// 	{
// 		ft_lstclear(&heada);
// 		return (0);
// 	}
// 	else
// 	{
// 		print_step(heada, "Current : ");
// 		ft_printf("\n");
// 		apply_butterfly(&heada, &headb);
// 		ft_lstclear(&heada);
// 	}
// 	return (0);
// }

int main(int ac, char **av)
{
	t_list *a = NULL;
    t_list *b;
	
    // a = parse_stack(ac, av);
	parse(ac, av, &a);
    b = NULL;
	
    // if (is_sorted(a))
    //     return (0);
	
    fill_index(a);              // TRÈS IMPORTANT
	
    // if (ft_lstsize(a) <= 5)
    //     sort_two_to_five(&a, &b);
    // else
    apply_butterfly(&a, &b);
	print_step(a, "Result : ");
	ft_lstclear(&a);

    return (0);
}


