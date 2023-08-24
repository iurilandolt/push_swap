/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:43:45 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/24 21:00:22 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void print_stack_targets(t_stack_node *lst)
{
	t_stack_node	*tmp;
	int	size;

	if (!lst)
	{
		ft_putendl_fd("stack not found", 1);
		return;
	}
	printf("+-------+----------+-------+--------+--------+\n");
	printf("| Value | Index    | Level | Cost   | Target |\n");
	printf("+-------+----------+-------+--------+--------+\n");
	tmp = lst;
	size = 0;
	while (tmp)
	{
		printf("| %-5d | %-8d | %-5d | %-6d | %-6d |\n", tmp->value, tmp->index, tmp->level, tmp->cost, tmp->target->value);
		tmp = tmp->next;
		size += 1;
	}
	printf("+-------+----------+-------+--------+--------+\n");
	printf("Stack index: %d\nStack size: %d\n", lst->index, size);
}

void	reset_targets(t_stack_node *lst_a, t_stack_node *lst_b)
{
	while (lst_b)
	{
		set_best_target(lst_a, lst_b);
		lst_b = lst_b->next;
	}

}

int	get_min_combined_cost(t_stack_node *lst_a, t_stack_node *lst_b)
{
	int	combined_cost;
	if (!lst_a && !lst_b)
		return (-1);
	combined_cost = lst_a->cost + lst_b->cost;
	return(combined_cost);
}

t_stack_node *get_optimal_b(t_stack_node *lst_a, t_stack_node *lst_b)
{
	int				min_combined_cost;
	t_stack_node	*marker;
	t_stack_node	*king;

	min_combined_cost = INT_MAX;
	king = lst_b;
	while (lst_b)
	{
		marker = lst_a;
		while (marker)
		{
			if (marker == lst_b->target)
				if (get_min_combined_cost(marker, lst_b) < min_combined_cost)
				{
					min_combined_cost = get_min_combined_cost(marker, lst_b);
					king = lst_b;
				}
			marker = marker->next;
		}
		lst_b = lst_b->next;
	}
	return(king);
}

int	can_rotate(t_stack_node *lst)
{
	int	moves;

	moves = 0;
	while(lst != get_first(lst))
	{
		lst = lst->previous;
		moves++;
	}
	return(moves);
}

int	can_reverse_rotate(t_stack_node *lst)
{
	int	moves;

	moves = 0;
	while(lst != get_last(lst))
	{
		lst = lst->next;
		moves++;
	}
	return(moves);
}

void	big_sort(t_stack_node **lst)
{
	t_stack_node *b;
	t_stack_node *marker;
	t_stack_node *optimal;

	b = NULL;
	while (stack_size(*lst) > 3)
		push(lst, &b, 'b');
	while (b)
	{
		reset_targets((*lst), b);
		optimal = get_optimal_b(*lst, b);
		while (b != optimal)
		{
			if ((optimal->index != 0 && optimal->target->index != 0
				&& (optimal->level <= 0 && optimal->target->level <= 0)))
					rotate_all(lst, &b);
			//if ((optimal->index != 0 && optimal->target->index != 0
				//&& (optimal->level > 0 && optimal->target->level > 0)))
					//reverse_rotate_all(lst, &b);
			else if(optimal->level <= 0)
				rotate(&b, 'b');
			else
				reverse_rotate(&b, 'b');
		}
		if ((*lst) == b->target)
			push(&b, lst, 'a');
		else if((*lst)->level <= 0)
			rotate(lst, 'a');
		else
			reverse_rotate(lst, 'a');
	}
	marker = get_lowest_value_node(*lst);
	while ((*lst) != get_lowest_value_node(*lst))
	{
		if (marker->level == 1)
			reverse_rotate(lst, 'a');
		else
			rotate(lst, 'a');
	}
}

int main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;

	a = NULL;
	b = NULL;

    if (argc <= 2)
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
			//printf("\n\nStack A/ END PROGRAM:\n");
			//print_stack(a);
			//printf("Stack B:\n");
			//print_stack(b);
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
