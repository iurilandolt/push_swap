/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:10:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/03 17:16:55 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

/* ACTIONS */
/* INPUT */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_error(char *msg);

int		ft_isdigit(int c);
int		is_sorted(t_stack_node *lst);
int		is_nbr(char *str);
int		input_error(char **array);
int 	ctoi(const char *nptr);

char	**ft_split(const char *str, char c);

size_t	ft_strlen(const char *s);
int		ft_strcmp(char *str1, char *str2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/* SORT */
/* STRUCT */

t_stack_node	*new_node(int value, int index);
t_stack_node *init_stack(char **args);

#endif
