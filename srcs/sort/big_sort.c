/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:54:12 by rlandolt          #+#    #+#             */
/*   Updated: 2023/09/06 12:39:36 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_nodes(t_stack_node **lst_a, t_stack_node **lst_b,
					t_stack_node *optimal)
{
	while ((*lst_b) != optimal)
	{
		if (optimal->level <= 0)
			rotate(lst_b, 'b');
		else
			reverse_rotate(lst_b, 'b');
	}
	while (*lst_a != optimal->target)
	{
		if (optimal->target->level <= 0)
			rotate(lst_a, 'a');
		else
			reverse_rotate(lst_a, 'a');
	}
}

void	optimal_rotation(t_stack_node **lst_a, t_stack_node **lst_b)
{
	t_stack_node	*optimal;

	reset_targets(*lst_a, *lst_b);
	optimal = get_optimal_b(*lst_a, *lst_b);
	while (*lst_a != optimal->target || *lst_b != optimal)
	{
		if (optimal->level <= 0 && optimal->target->level <= 0)
			rotate_all(lst_a, lst_b);
		else if (optimal->level > 0 && optimal->target->level > 0)
			reverse_rotate_all(lst_a, lst_b);
		else
			move_nodes(lst_a, lst_b, optimal);
	}
	push(lst_b, lst_a, 'a');
}

void	big_sort(t_stack_node **lst)
{
	t_stack_node	*b;
	t_stack_node	*marker;

	b = NULL;
	while (stack_size(*lst) > 3)
		push(lst, &b, 'b');
	small_sort(lst);
	while (b)
		optimal_rotation(lst, &b);
	marker = get_lowest_value_node(*lst);
	while ((*lst) != get_lowest_value_node(*lst))
	{
		if (marker->level > 0)
			reverse_rotate(lst, 'a');
		else
			rotate(lst, 'a');
	}
}
