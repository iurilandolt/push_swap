/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:10:00 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/16 20:14:48 by rlandolt         ###   ########.fr       */
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
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

typedef struct s_tracker
{
	int	moves;
	int	top;
	int	med;
	int	bot;

}t_tracker;


/* ACTIONS */


void	swap(t_stack_node *lst, char target);
void	rotate_cw(t_stack_node **lst, char target);
void	rotate_ccw(t_stack_node **lst, char target);
void	rotate_all_cw(t_stack_node **lst_a, t_stack_node **lst_b);
void	rotate_all_ccw(t_stack_node **lst_a, t_stack_node **lst_b);
void	push(t_stack_node **src, t_stack_node **dst, char target);

/* INPUT */

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl_fd(char *str, int fd);
void			ft_error(char *msg);

int				ft_isdigit(int c);
int				is_nbr(char *str);
int				input_error(char **array);
int 			ctoi(const char *nptr);

char			**ft_split(const char *str, char c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);

/* SORT */

/* STRUCT */

void			print_stack(t_stack_node *lst);
int				is_sorted(t_stack_node *lst);
int				is_dupe(t_stack_node *lst);
t_stack_node	*new_node(int value, int index);
t_stack_node 	*init_stack(char **args);
void			free_stacks(int count, ...);
void 			re_index(t_stack_node *lst);
t_stack_node	*get_first(t_stack_node *lst);
t_stack_node	*get_last(t_stack_node *lst);

#endif
