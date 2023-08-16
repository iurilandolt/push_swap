#include "../../include/push_swap.h"

void	rotate_cw(t_stack_node **lst)
{
	t_stack_node	*last;

	last = get_last(*lst);
	last->previous->next = NULL;
	last->next = (*lst);
	(*lst)->previous = last;
	(*lst) = last;
	(*lst)->previous = NULL;
}

void	rotate_ccw(t_stack_node **lst)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = (*lst)->next;
	first->previous = NULL;
	last = get_last(*lst);
	last->next = (*lst);
	(*lst)->previous = last;
	(*lst)->next = NULL;
	(*lst) = first;
}
