/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:33:59 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/17 20:18:27 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_3(t_stack_node **lst)
{
	t_tracker tmp;

	tmp.top = (*lst)->value;
	tmp.med = (*lst)->next->value;
	tmp.bot = (*lst)->next->next->value;
	if (tmp.top > tmp.med && tmp.med < tmp.bot && tmp.top < tmp.bot)
		swap(*lst, 'a');
	if (tmp.top > tmp.med && tmp.med > tmp.bot && tmp.bot < tmp.top)
	{
		swap(*lst, 'a');
		rotate_cw(lst, 'a');
	}
	if (tmp.top > tmp.med && tmp.top > tmp.bot && tmp.med < tmp.bot)
		rotate_ccw(lst, 'a');
	if (tmp.top < tmp.med && tmp.med > tmp.bot && tmp.bot > tmp.top)
	{
		swap(*lst, 'a');
		rotate_ccw(lst, 'a');
	}
	if (tmp.top < tmp.med && tmp.top > tmp.bot && tmp.med > tmp.bot)
		rotate_cw(lst, 'a');
}



void	sort_5(t_stack_node **lst)
{
	t_stack_node *b;
	//t_tracker tmp;

	b = NULL;
	push(lst, &b, 'b');
	push(lst, &b, 'b');
	sort_3(lst);



	printf("\n\nStack A:\n");
	print_stack(*lst);
	printf("Stack B:\n");
	print_stack(b);
}
