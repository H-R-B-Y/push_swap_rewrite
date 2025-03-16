/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:09:34 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/16 13:45:46 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	a_chunk_is_sorted(t_cdll *stack, size_t sz)
{
	size_t		i;
	t_cdll_node	*node;

	if (!stack || sz == 0)
		return (0);
	if (sz == 1)
		return (1);
	i = 1;
	node = stack->head;
	while (i < sz)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	b_chunk_is_sorted(t_cdll *stack, size_t sz)
{
		size_t		i;
	t_cdll_node	*node;

	if (!stack || sz == 0)
		return (0);
	if (sz == 1)
		return (1);
	i = 1;
	node = stack->head;
	while (i < sz)
	{
		if (node->data < node->next->data)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

int	anon_is_sorted(t_push_swap *meta, t_cdll *stack, size_t sz)
{
	if (stack == meta->stack_a)
		return (a_chunk_is_sorted(stack, sz));
	if (stack == meta->stack_b)
		return (b_chunk_is_sorted(stack, sz));
	else
		return (0);
}
