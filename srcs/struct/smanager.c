/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smanager.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:47:28 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/24 14:18:08 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	calculate_moves(t_stack_node *lst)
{
	int	moves;

	moves = 0;
	if (lst->level <= 0)
	{
		while(lst != get_first(lst))
		{
			lst = lst->previous;
			moves++;
		}
	}
	if (lst->level > 0)
	{
		while(lst != get_last(lst))
		{
			lst = lst->next;
			moves++;
		}
		moves += 1;
	}
	return(moves);
}

void	set_node_level(t_stack_node *lst)
{
	int	size;

	if (!lst)
		return;
	size = stack_size(lst);
	while (lst)
	{
		if (lst->index < size / 2)
			lst->level = -1;
		else if (lst->index > size / 2)
			lst->level = 1;
		else
			lst->level = 0;
		lst=lst->next;
	}
}

void	set_node_cost(t_stack_node *lst)
{
	if (!lst)
		return;
	while(lst)
	{
		lst->cost = calculate_moves(lst);
		lst = lst->next;
	}
}

void	set_best_target(t_stack_node *lst_a, t_stack_node *lst_b)
{
	t_stack_node *marker;
	int dif;
	int min_dif;

	marker = lst_a;
	lst_b->target = get_lowest_value_node(lst_a);
	//printf("begin func, %d target set to %d\n", lst_b->value, lst_b->target->value);
	min_dif = INT_MAX;
	while (marker)
	{
		dif = marker->value - lst_b->value;
		if (marker->value > lst_b->value)
		{

			if (dif < min_dif)
			{
				min_dif = dif;
				lst_b->target = marker;
				//printf("inside loop, %d target set to %d\n", lst_b->value, lst_b->target->value);
			}
		}
		marker = marker->next;
	}
}

void	re_factor(t_stack_node *lst)
{
	re_index(lst);
	set_node_level(lst);
	set_node_cost(lst);
}



/*
int	cw_moves(t_stack_node *lst)
{
	int	moves;

	moves = 0;
	while(lst != get_first(lst))
	{
		lst = lst->previous;
		moves++;
	}
	return(moves);
}

int	ccw_moves(t_stack_node *lst)
{
	int	moves;

	moves = 0;
	while(lst != get_last(lst))
	{
		lst = lst->next;
		moves++;
	}
	return(moves);
}
*/
