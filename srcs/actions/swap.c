#include "../../include/push_swap.h"

void	swap(t_stack_node *lst)
{
	int	swap;

	swap = lst->value;
	lst->value = lst->next->value;
	lst->next->value = swap;
}
