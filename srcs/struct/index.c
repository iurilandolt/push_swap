/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:19:02 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/17 23:52:50 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


void re_index(t_stack_node *lst)
{
	t_stack_node	*tmp;
	int	index;

	if (!lst)
		ft_error("Error: re-indexing failed.");
	tmp = lst;
	index = 0;
	while (tmp)
	{
		tmp->index = index;
		index += 1;
		tmp = tmp->next;
	}
}

t_stack_node	*get_first(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (tmp->previous)
		tmp = tmp->previous;
	return(tmp);
}

t_stack_node	*get_last(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return(tmp);
}

t_stack_node	*get_lowest_value_node(t_stack_node *lst)
{

	t_stack_node	*target;
	int				lowest;

	lowest = lst->value;
	target = lst;
	lst = lst->next;
	while (lst)
	{

		if (lst->value < lowest)
		{
			lowest = lst->value;
			target = lst;
		}
		lst = lst->next;
	}
	return(target);
}

t_stack_node	*get_highest_value_node(t_stack_node *lst)
{

	t_stack_node	*target;
	int				highest;

	highest = lst->value;
	target = lst;
	lst = lst->next;
	while (lst)
	{

		if (lst->value > highest)
		{
			highest = lst->value;
			target = lst;
		}
		lst = lst->next;
	}
	return(target);
}


