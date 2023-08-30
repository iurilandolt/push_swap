/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:49:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 16:19:04 by rlandolt         ###   ########.fr       */
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

void	check_stack(t_stack_node *lst)
{
	if (is_sorted(lst))
		ft_error("");
	if (is_dupe(lst))
		ft_error("Error");
	re_factor(lst);
}

t_stack_node	*init_stack(char **args)
{
	t_stack_node	*first;
	t_stack_node	*new;
	t_stack_node	*last;
	int				index;

	index = -1;
	while (args[++index])
	{
		if (index == 0)
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
	check_stack(first);
	return (first);
}

int	ctoi(const char *nptr)
{
	long int	n;
	int			sign;

	sign = 1;
	n = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + (*nptr++ - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			ft_error("Error");
	}
	return (n * sign);
}

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
