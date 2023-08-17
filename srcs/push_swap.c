/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/17 19:23:39 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

	b = NULL;
	push(lst, &b, 'b');
	push(lst, &b, 'b');
	sort_3(lst);



	printf("\n\nStack A:\n");
	print_stack(*lst);
	printf("Stack B:\n");
	print_stack(b);
}

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	a = NULL;
	b = NULL;

    if (argc <= 2)
		return(1);
    else
    {
		argv++;
        if (!input_error(argv))
		{
			a = init_stack(argv);

			if (stack_size(a) == 3)
				sort_3(&a);
			if (stack_size(a) == 5)
				sort_5(&a);
/*
			printf("\n\nStack A:\n");
			print_stack(a);
			printf("Stack B:\n");
			print_stack(b);

*/
			free_stacks(2, a, b);
		}
    }
    return 0;
}


/*
		while (argv)
        {
            printf("%s\n", *argv);
			if(!*(argv + 1))
				break;
            argv++;
        }
*/
