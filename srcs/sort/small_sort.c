/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:33:59 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/25 12:09:55 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack_node **lst)
{
	int_tracker tmp;

	tmp.top = (*lst)->value;
	tmp.med = (*lst)->next->value;
	tmp.bot = (*lst)->next->next->value;
	if (tmp.top > tmp.med && tmp.med < tmp.bot && tmp.bot > tmp.top)
		swap(*lst, 'a');
	if (tmp.top > tmp.med && tmp.med > tmp.bot && tmp.bot < tmp.top)
	{
		swap(*lst, 'a');
		reverse_rotate(lst, 'a');
	}
	if (tmp.top > tmp.med && tmp.med < tmp.bot && tmp.bot < tmp.top)
		rotate(lst, 'a');
	if (tmp.top < tmp.med && tmp.med > tmp.bot && tmp.bot > tmp.top)
	{
		swap(*lst, 'a');
		rotate(lst, 'a');
	}
	if (tmp.top < tmp.med && tmp.med > tmp.bot && tmp.bot < tmp.top)
		reverse_rotate(lst, 'a');
}
/*make sure level is <= or just < 0?*/
void	sort_4_5(t_stack_node **lst)
{
	t_stack_node *b;
	t_stack_node *marker;

	b = NULL;
	while (stack_size(*lst) > 3)
			push(lst, &b, 'b');
	sort_3(lst);
	while (b)
	{
		set_best_target(*lst, b);
		if ((*lst) == b->target)
			push(&b, lst, 'a');
		else if((*lst)->level < 0)
			rotate(lst, 'a');
		else
			reverse_rotate(lst, 'a');
	}
	marker = get_lowest_value_node(*lst);
	while ((*lst) != get_lowest_value_node(*lst))
	{
		if (marker->level >= 0)
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

/*
void	sort_4_5(t_stack_node **lst)
{
	t_stack_node *b;
	t_stack_node *marker;

	b = NULL;
	while (stack_size(*lst) > 3)
			push(lst, &b, 'b');
	sort_3(lst);
	while (b)
	{
		set_best_target(*lst, b);
		//if (b->next && b->next->value > b->value)
			//swap(b, 'b');
		if ((*lst) == b->target)
			push(&b, lst, 'a');
		else if((*lst)->level < 0)
			rotate(lst, 'a');
		else
			reverse_rotate(lst, 'a');
	}
	marker = get_lowest_value_node(*lst);
	while ((*lst) != get_lowest_value_node(*lst))
	{
		if (marker->level == 1)
			reverse_rotate(lst, 'a');
		else
			rotate(lst, 'a');
	}
}
*/
