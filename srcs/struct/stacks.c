/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:49:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/03 23:27:16 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void print_stack(t_stack_node *lst)
{
	t_stack_node *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("Value: %d @ index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
}

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

t_stack_node	*new_node(int value, int index)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		ft_error("failed to allocate node");
	new->value = value;
	new->index = index;
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_stack_node *init_stack(char **args)
{
	t_stack_node	*first;
	t_stack_node	*new;
	t_stack_node	*last;
	int				index;

	index = -1;
	while(args[++index])
	{
		if(index == 0)
		{
			first = new_node(ctoi(args[index]), index);
			last = first;
		}
		else
		{
			new = new_node(ctoi(args[index]), index);
			last->next = new;
			new->previous = last;
			last = new;
		}
	}
	/*
	here instead of only checking if the list is sorted
	we will also check for dupes here, so idealy creating a function to check if list is valid

	*/
	if (is_sorted(first))
		ft_error("this some bs");
	return(first);
}
/*
	t_stack_node *tmp = first;
	while (tmp)
	{
		printf("|| Value: %d @ index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
*/
