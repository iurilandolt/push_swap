/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 15:30:41 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_swap(int count, char **value)
{
	t_stack_node	*a;

	a = NULL;
	value++;
	if (count == 2)
		a = handle_single_argv(value);
	else
	{
		if (!input_error(value))
			a = init_stack(value);
	}
	if (a)
	{
		if (stack_size(a) <= 5)
			small_sort(&a);
		else
			big_sort(&a);
		free_stack(a);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("");
	push_swap(argc, argv);
	return (0);
}
/*
int main(int argc, char **argv)
{
	t_stack_node	*a;

	a = NULL;
	argv++;
    if (argc < 2)
		ft_error("");
    else
    {
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
*/
