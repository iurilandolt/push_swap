/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:54:29 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/07 19:57:44 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void push_node(t_stack_node **src, t_stack_node **dst, char target)
{
	t_stack_node *new;

	if ((!*dst))
		(*dst) = new_node((*src)->value, (*src)->index);
	else
	{
		new = new_node((*src)->value, (*src)->index);
		new->next = (*dst);
		(*dst)->previous = new;
		(*dst) = new;
	}
	if (!(*src)->next)
	{
		free((*src));
		(*src) = NULL;
	}
	else
	{
		(*src) = (*src)->next;
		free((*src)->previous);
		(*src)->previous = NULL;
	}
	if (target == 'a')
		ft_putendl_fd("pa", 1);
	if (target == 'b')
		ft_putendl_fd("pb", 1);
}
