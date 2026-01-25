#include "pushswap.h"

void	printlist(t_list *head)
{
	t_list	*current = head;

	while (current != NULL)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
}

void    print_step(t_list *head, char *str)
{
	ft_printf("%s\n", str);
	printlist(head);
}