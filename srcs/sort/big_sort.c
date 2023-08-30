/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:54:12 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 15:40:22 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_together(t_stack_node **lst_a,
					t_stack_node **lst_b, t_stack_node *optimal)
{
	int	prev_index_a;
	int	prev_index_b;

	while (*lst_b != optimal || *lst_a != optimal->target)
	{
		prev_index_a = (*lst_a)->index;
		prev_index_b = (*lst_b)->index;
		if (optimal->level <= 0 && optimal->target->level <= 0)
			rotate_all(lst_a, lst_b);
		else if (optimal->level > 0 && optimal->target->level > 0)
			reverse_rotate_all(lst_a, lst_b);
		else if (optimal->index == 0 || optimal->target->index == 0)
			break ;
		if ((*lst_a)->index == prev_index_a && (*lst_b)->index == prev_index_b)
			break ;
	}
}

void	move_b(t_stack_node **lst_a, t_stack_node **lst_b)
{
	t_stack_node	*optimal;

	optimal = get_optimal_b(*lst_a, *lst_b);
	move_together(lst_a, lst_b, optimal);
	while ((*lst_b) != optimal)
	{
		if (optimal->level <= 0)
			rotate(lst_b, 'b');
		else
			reverse_rotate(lst_b, 'b');
	}
}

void	move_a(t_stack_node **lst_a, t_stack_node **lst_b)
{
	while (*lst_a != (*lst_b)->target)
	{
		if ((*lst_b)->target->level <= 0)
			rotate(lst_a, 'a');
		else
			reverse_rotate(lst_a, 'a');
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
	{
		reset_targets((*lst), b);
		move_b(lst, &b);
		move_a(lst, &b);
	}
	marker = get_lowest_value_node(*lst);
	while ((*lst) != get_lowest_value_node(*lst))
	{
		if (marker->level > 0)
			reverse_rotate(lst, 'a');
		else
			rotate(lst, 'a');
	}
}
