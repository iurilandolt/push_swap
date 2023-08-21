/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/21 15:32:43 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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




			//if (stack_size(a) == 3)
				//sort_3(&a);
			if (stack_size(a) == 5)
				sort_5(&a);

			printf("\n\nStack A/ END PROGRAM:\n");
			print_stack(a);
/*

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
