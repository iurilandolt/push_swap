/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:02:06 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/24 13:06:39 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_size(t_stack_node *lst)
{
	t_stack_node *tmp;
	int	size;

	if (!lst)
		return(0);
	tmp = lst;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return(size);
}

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
			return;
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
	printf("+-------+----------+-------+--------+\n");
	printf("| Value | Index    | Level | Cost   |\n");
	printf("+-------+----------+-------+--------+\n");
	tmp = lst;
	size = 0;
	while (tmp)
	{
		printf("| %-5d | %-8d | %-5d | %-6d |\n", tmp->value, tmp->index, tmp->level, tmp->cost);
		tmp = tmp->next;
		size += 1;
	}
	printf("+-------+----------+-------+--------+\n");
	printf("Stack index: %d\nStack size: %d\n", lst->index, size);
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
