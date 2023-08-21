/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:33:59 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/21 18:51:38 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack_node **lst)
{
	t_tracker tmp;

	tmp.top = (*lst)->value;
	tmp.med = (*lst)->next->value;
	tmp.bot = (*lst)->next->next->value;
	if (tmp.top > tmp.med && tmp.med < tmp.bot && tmp.bot > tmp.top)
		swap(*lst, 'a');
	if (tmp.top > tmp.med && tmp.med > tmp.bot && tmp.bot < tmp.top)
	{
		swap(*lst, 'a');
		rotate_ccw(lst, 'a');
	}
	if (tmp.top > tmp.med && tmp.med < tmp.bot && tmp.bot < tmp.top)
		rotate_cw(lst, 'a');
	if (tmp.top < tmp.med && tmp.med > tmp.bot && tmp.bot > tmp.top)
	{
		swap(*lst, 'a');
		rotate_cw(lst, 'a');
	}
	if (tmp.top < tmp.med && tmp.med > tmp.bot && tmp.bot < tmp.top)
		rotate_ccw(lst, 'a');
}



void	sort_5(t_stack_node **lst)
{
	t_stack_node *b;
	t_stack_node *marker;

	b = NULL;
	push(lst, &b, 'b');
	push(lst, &b, 'b');
	sort_3(lst);
	while (b)
	{
		if (b->next && b->value < b->next->value)
			swap(b, 'b');
		if (b->value < (*lst)->value || b->value > get_last(*lst)->value)
			push(&b, lst, 'a');
		else
			while ((*lst) != get_highest_value_node(*lst))
			{
				if (get_highest_value_node(*lst)->level == 1)
					rotate_ccw(lst, 'a');
				else
					rotate_cw(lst, 'a');
			}
	}
	marker = get_lowest_value_node(*lst);
	while ((*lst) != get_lowest_value_node(*lst))
	{
		if (marker->level == 1)
			rotate_ccw(lst, 'a');
		else
			rotate_cw(lst, 'a');
	}

}
