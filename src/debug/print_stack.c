/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:26:17 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 15:34:52 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stack(t_cdll *st)
{
	t_cdll_node	*node;

	if (!st || st->count == 0)
		return ;
	node = st->head;
	ft_printf("HEAD-> ");
	while (node != st->tail)
	{
		ft_printf("%d, ", node->data);
		node = node->next;
	}
	ft_printf("%d <-TAIL \n", node->data);
	return ;
}
