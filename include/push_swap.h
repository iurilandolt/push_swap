/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:10:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/24 18:57:09 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					level;
	int					cost;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
	struct s_stack_node *target;
}	t_stack_node;

typedef struct i_tracker
{
	int	top;
	int	med;
	int	bot;

}int_tracker;

typedef struct n_tracker
{
	t_stack_node *node_a;
	t_stack_node *node_b;

}node_tracker;


/* ACTIONS */

void			swap(t_stack_node *lst, char target);
void			rotate(t_stack_node **lst, char target);
void			reverse_rotate(t_stack_node **lst, char target);
void			rotate_all(t_stack_node **lst_a, t_stack_node **lst_b);
void			reverse_rotate_all(t_stack_node **lst_a, t_stack_node **lst_b);
void			push(t_stack_node **src, t_stack_node **dst, char target);

/* INPUT */

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_error(char *msg);

int				is_sorted(t_stack_node *lst);
int				is_dupe(t_stack_node *lst);
int				ft_isdigit(int c);
int				is_nbr(char *str);
int				input_error(char **array);
int 			ctoi(const char *nptr);

char			**ft_split(const char *str, char c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/* SORT */

void	small_sort(t_stack_node **lst);

/* STRUCT */

void			print_stack(t_stack_node *lst);

t_stack_node	*new_node(int value, int index);
t_stack_node 	*init_stack(char **args);
int				stack_size(t_stack_node *lst);
void			free_stacks(int count, ...);
void 			re_index(t_stack_node *lst);
void			re_factor(t_stack_node *lst);
t_stack_node	*get_first(t_stack_node *lst);
t_stack_node	*get_last(t_stack_node *lst);
t_stack_node	*get_lowest_value_node(t_stack_node *lst);
t_stack_node	*get_highest_value_node(t_stack_node *lst);
void			 set_best_target(t_stack_node *lst_a, t_stack_node *lst_b);

#endif
