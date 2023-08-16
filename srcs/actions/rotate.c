/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:49:58 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/16 17:36:29 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rotate_cw(t_stack_node **lst, char target)
{
	t_stack_node	*last;

	if (!(*lst) || !(*lst)->next)
		return;
	last = get_last(*lst);
	last->previous->next = NULL;
	last->next = (*lst);
	(*lst)->previous = last;
	(*lst) = last;
	(*lst)->previous = NULL;
	if (target == 'a')
		ft_putendl_fd("ra", 1);
	if (target == 'b')
		ft_putendl_fd("rb", 1);
}

void	rotate_ccw(t_stack_node **lst, char target)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!(*lst) || !(*lst)->next)
		return;
	first = (*lst)->next;
	first->previous = NULL;
	last = get_last(*lst);
	last->next = (*lst);
	(*lst)->previous = last;
	(*lst)->next = NULL;
	(*lst) = first;
	if (target == 'a')
		ft_putendl_fd("rra", 1);
	if (target == 'b')
		ft_putendl_fd("rrb", 1);
}

void	rotate_all_cw(t_stack_node **lst_a, t_stack_node **lst_b)
{
	rotate_cw(lst_a, 'x');
	rotate_cw(lst_b, 'x');
	ft_putendl_fd("rr", 1);
}

void	rotate_all_ccw(t_stack_node **lst_a, t_stack_node **lst_b)
{
	rotate_cw(lst_a, 'x');
	rotate_cw(lst_b, 'x');
	ft_putendl_fd("rrr", 1);
}
