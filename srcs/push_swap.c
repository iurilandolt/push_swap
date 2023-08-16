/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/16 17:51:18 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	a = NULL;
	b = NULL;

    if (argc < 2)
		return(1);
    else
    {
		argv++;
        if (!input_error(argv))
		{
			a = init_stack(argv);

			printf("\n\nStack A:\n");
			print_stack(a);
			printf("Stack B:\n");
			print_stack(b);
			free_stack(a);
			free_stack(b);
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
