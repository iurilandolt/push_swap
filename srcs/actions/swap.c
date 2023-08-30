/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlandolt <rlandolt@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:50:20 by rlandolt          #+#    #+#             */
/*   Updated: 2023/08/30 15:33:32 by rlandolt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	swap(t_stack_node *lst, char target)
{
	int	swap;

	if (!lst || !lst->next)
		return ;
	swap = lst->value;
	lst->value = lst->next->value;
	lst->next->value = swap;
	if (target == 'a')
		ft_putendl_fd("sa", 1);
	if (target == 'b')
		ft_putendl_fd("sb", 1);
}
