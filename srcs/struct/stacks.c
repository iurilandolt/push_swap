/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:49:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/16 18:17:22 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack_node	*new_node(int value, int index)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new)
		ft_error("Error: failed to allocate node");
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
		ft_error("Error: data already sorted.");
	return(first);
}

/*
void	free_stack(t_stack_node *ptr)
{
	t_stack_node	*tmp;
	t_stack_node	*curr;

	if (!ptr)
		ft_error("Error: failed free call.");
	curr = ptr;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	ptr = NULL;
}
*/

void	free_stacks(int count, ...)
{
	va_list args;
	t_stack_node *ptr;
	t_stack_node *tmp;
	t_stack_node *curr;
	int freed = 0;

	va_start(args, count);
	while (freed < count)
	{
		ptr = va_arg(args, t_stack_node*);
		if (!ptr)
			ft_error("Error: failed free call.");
		curr = ptr;
		while (curr)
		{
			tmp = curr;
			curr = curr->next;
			free(tmp);
		}
		freed++;
	}
	va_end(args);
}

void print_stack(t_stack_node *lst)
{
	t_stack_node	*tmp;
	int	size;

	if (!lst)
	{
		ft_putendl_fd("stack not found", 1);
		return;
	}
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

/*
void reverse_print(t_stack_node *lst)
{
	t_stack_node	*tmp;


	if (!lst)
	{
		ft_putendl_fd("stack not found", 1);
		return;
	}
	tmp = get_last(lst);
	printf("REVERSE PRINT START\n");
	while (tmp->previous)
	{
		printf("Value: %d @ index: %d\n", tmp->value, tmp->index);
		tmp = tmp->previous;

	}
	printf("Value: %d @ index: %d\n", tmp->value, tmp->index);
	printf("REVERSE PRINT END\n");

}
*/
