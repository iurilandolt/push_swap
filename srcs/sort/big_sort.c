/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:54:12 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/24 14:32:35 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_min_combined_cost(t_stack_node *lst_a, t_stack_node *lst_b)
{
	int	combined_cost;
	if (!lst_a && !lst_b)
		return (-1);
	combined_cost = lst_a->cost + lst_b->cost;
	return(combined_cost);
}

void	big_sort(t_stack_node **lst)
{
	t_stack_node 	*b;
	node_tracker	*ptr;
	int				min_combined_cost;

	ptr->node_b = b;
	while (stack_size(*lst) > 3)
		push(lst, &b, 'a');
	set_best_target(*lst, b);
	printf("Stack B:\n");
	print_stack(b);
	while (ptr->node_b)
	{
		min_combined_cost = get_min_combined_cost(*lst, b);
		ptr->node_a = (*lst);
		while (ptr->node_a)
		{
			if(get_min_combined_cost(ptr->node_a, ptr->node_b) < min_combined_cost)
			{
				min_combined_cost = get_min_combined_cost(ptr->node_a, ptr->node_b);
				ptr->node_b->target = ptr->node_a;
			}
			ptr->node_a = ptr->node_a->next;
		}
		ptr->node_b = ptr->node_b->next;
	}
}
