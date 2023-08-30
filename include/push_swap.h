/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:10:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 16:07:46 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					level;
	int					cost;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
	struct s_stack_node	*target;
}	t_stack_node;

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
int				ctoi(const char *nptr);

char			**ft_split(const char *str, char c);
char			**clean(char **array, int i);
int				substr_count(const char *str, char c);
t_stack_node	*handle_single_argv(char **value);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/* SORT */

void			small_sort(t_stack_node **lst);
void			big_sort(t_stack_node **lst);

/* STRUCT */

t_stack_node	*new_node(int value, int index);
t_stack_node	*init_stack(char **args);
int				stack_size(t_stack_node *lst);
void			free_stack(t_stack_node *ptr);
void			re_index(t_stack_node *lst);
void			re_factor(t_stack_node *lst);
void			reset_targets(t_stack_node *lst_a, t_stack_node *lst_b);
t_stack_node	*get_optimal_b(t_stack_node *lst_a, t_stack_node *lst_b);
t_stack_node	*get_first(t_stack_node *lst);
t_stack_node	*get_last(t_stack_node *lst);
t_stack_node	*get_lowest_value_node(t_stack_node *lst);
t_stack_node	*get_highest_value_node(t_stack_node *lst);

#endif
