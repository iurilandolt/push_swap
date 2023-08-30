/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:33:59 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 16:20:16 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack_node **lst)
{
	t_stack_node	*highest;

	highest = get_highest_value_node(*lst);
	if (*lst == highest)
		rotate(lst, 'a');
	else if ((*lst)->next == highest)
		reverse_rotate(lst, 'a');
	if ((*lst)->value > (*lst)->next->value)
		swap(*lst, 'a');
}

void	sort_4_5(t_stack_node **lst)
{
	t_stack_node	*b;
	t_stack_node	*marker;

	b = NULL;
	while (stack_size(*lst) > 3)
		push(lst, &b, 'b');
	sort_3(lst);
	while (b)
	{
		reset_targets(*lst, b);
		if ((*lst) == b->target)
			push(&b, lst, 'a');
		else if ((*lst)->level <= 0)
			rotate(lst, 'a');
		else
			reverse_rotate(lst, 'a');
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

void	small_sort(t_stack_node **lst)
{
	if (stack_size(*lst) == 2)
	{
		if ((*lst)->value > (*lst)->next->value)
			swap(*lst, 'a');
	}
	else if (stack_size(*lst) == 3)
		sort_3(lst);
	else
		sort_4_5(lst);
}
