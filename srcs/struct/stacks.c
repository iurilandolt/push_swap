/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:49:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/07 18:19:39 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	if (is_sorted(first) || is_dupe(first))
		ft_error("this some bs");
	return(first);
}

void	free_stack(t_stack_node *ptr)
{
	t_stack_node	*tmp;
	t_stack_node	*curr;

	if (!ptr)
		ft_error("free fkep up");
	curr = ptr;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	ptr = NULL;
}

void print_stack(t_stack_node *lst)
{
	t_stack_node	*tmp;
	int	size;

	tmp = lst;
	size = 0;
	while (tmp)
	{
		printf("Value: %d @ index: %d\n", tmp->value, tmp->index);
		tmp = tmp->next;
		size += 1;
	}
	printf("Stack index: %d\nStack size: %d\n", lst->index, size);
}


