/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/29 17:48:32 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node	*a;

	a = NULL;
    if (argc < 2)
		ft_error("");
    else
    {
		argv++;
        if (!input_error(argv))
		{
			a = init_stack(argv);
			if (stack_size(a) <= 5)
				small_sort(&a);
			else
				big_sort(&a);
			free_stack(a);
		}
    }
    return 0;
}



