/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:19:02 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/16 18:35:50 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_dupe(t_stack_node *lst)
{
	t_stack_node	*i;
	t_stack_node	*j;

	i = lst;

	while (i)
	{
		j = i->next;
		while (j)
		{
			//printf("%d vs %d\n", i->value, j->value);
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_stack_node	*get_last(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return(tmp);
}

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

/*
t_stack_node	*get_first(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (tmp->previous)
		tmp = tmp->previous;
	return(tmp);
}
*/
