/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:02:06 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/29 17:36:05 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_best_target(t_stack_node *lst_a, t_stack_node *lst_b)
{
	t_stack_node *marker;
	int dif;
	int min_dif;

	marker = lst_a;
	lst_b->target = get_lowest_value_node(lst_a);
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
			}
		}
		marker = marker->next;
	}
}

void	reset_targets(t_stack_node *lst_a, t_stack_node *lst_b)
{
	while (lst_b)
	{
		set_best_target(lst_a, lst_b);
		lst_b = lst_b->next;
	}

}

int	get_min_combined_cost(t_stack_node *lst_a, t_stack_node *lst_b)
{
	int	combined_cost;
	if (!lst_a || !lst_b)
		return (-1);
	combined_cost = lst_a->cost + lst_b->cost;
	return(combined_cost);
}

t_stack_node *get_optimal_b(t_stack_node *lst_a, t_stack_node *lst_b)
{
	int				min_combined_cost;
	t_stack_node	*marker;
	t_stack_node	*optimal;

	min_combined_cost = INT_MAX;
	optimal = lst_b;
	while (lst_b)
	{
		marker = lst_a;
		while (marker)
		{
			if (marker == lst_b->target)
				if (get_min_combined_cost(marker, lst_b) < min_combined_cost)
				{
					min_combined_cost = get_min_combined_cost(marker, lst_b);
					optimal = lst_b;
				}
			marker = marker->next;
		}
		lst_b = lst_b->next;
	}
	return(optimal);
}

