/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:25:44 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/03 19:36:10 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	is_sorted(t_stack_node *lst)
{
	t_stack_node *tmp;
	tmp = lst;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	free(tmp);
	return (1);
}

int	is_nbr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while(*str)
	{
		if (*str < 48 || *str > 57)
			return (0);
		str++;
	}
	return (1);
}

int	input_error(char **array)
{
	int i;
	int j;
	int skip_i;
	int skip_j;

	i = 0;
	skip_i = 0;
	skip_j = 0;
	while(array[i])
	{
		while (array[i][skip_i] == '0' || array[i][skip_i] == '+')
			skip_i++;
		j = i + 1;
		if (!is_nbr(array[i]))
			ft_error("not a number");

		while(array[j])
		{
			while (array[j][skip_j] == '0' || array[j][skip_j] == '+' )
				skip_j++;
			if (ft_strcmp(&array[i][skip_i], &array[j][skip_j]) == 0)
				ft_error("found dupe");
			j++;
			skip_j = 0;
		}
		i++;
		skip_i = 0;
	}
	return (0);
}



int ctoi(const char *nptr)
{
	long int n;
	int sign;

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
			ft_error("over limits");
	}
	return (n * sign);
}
