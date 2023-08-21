/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/21 20:17:40 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void set_best_target(t_stack_node *lst_a, t_stack_node *lst_b)
{
	int	dif;
	int min_dif;

	dif = lst_a->value - lst_b->value;
	min_dif = dif;
	lst_b->target = lst_a;
	while (lst_b)
	{
		while (lst_a)
		{
			dif = lst_a->value - lst_b->value;
			if (dif > 0 && dif < min_dif)
				{
					min_dif = dif;
					lst_b->target = lst_a;
				}
			lst_a = lst_a->next;
		}
		lst_b = lst_b->next;
	}
}

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;

    if (argc <= 2)
		ft_error("Error");
    else
    {
		argv++;
        if (!input_error(argv))
		{
			a = init_stack(argv);
			push(&a, &b, 'b');
			push(&a, &b, 'b');
			set_best_target(a, b);
			printf("%d\n", b->target->value);
/*
			if (stack_size(a) == 3)
				sort_3(&a);
			if (stack_size(a) == 5)
				sort_5(&a);
*/


			printf("\n\nStack A/ END PROGRAM:\n");
			print_stack(a);
			printf("Stack B:\n");
			print_stack(b);


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
