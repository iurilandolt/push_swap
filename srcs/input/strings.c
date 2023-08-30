/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:19:30 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 15:37:50 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	pos;

	pos = 0;
	while (*s++)
		pos++;
	return (pos);
}

size_t	arrlen(char **arr)
{
	size_t	size;

	size = 0;
	while (*arr)
	{
		size++;
		arr++;
	}
	return (size);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(src + i) && size && i < size - 1)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size - i != 0)
		*(dest + i) = '\0';
	return (ft_strlen(src));
}

t_stack_node	*handle_single_argv(char **value)
{
	t_stack_node	*a;
	char			**args;
	int				i;
	int				j;

	a = NULL;
	i = 0;
	args = ft_split(*value, ' ');
	j = arrlen(args);
	while (i < j)
		input_error(args + i++);
	a = init_stack(args);
	clean(args, j);
	return (a);
}
