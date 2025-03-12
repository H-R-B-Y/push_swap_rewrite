/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_correct_place.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:20:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/12 14:28:26 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_cdll_node	*a_find_position(t_cdll *stack, int number)
{
	t_cdll_node	*node;
	size_t		i;

	if (!stack || stack->count == 0)
		return ((void *)0);
	if ((stack->max_node && number > stack->max) || (stack->min_node && number < stack->min) || stack->count == 1)
		return (stack->min_node);
	node = stack->head;
	i = 0;
	while (i < stack->count)
	{
		if (number > node->prev->data && number < node->data)
			return (node);
		node = node->next;
		i++;
	}
	return (node);
}

t_cdll_node	*b_find_position(t_cdll *stack, int number)
{
	t_cdll_node	*node;
	size_t		i;

	if (!stack || stack->count == 0)
		return ((void *)0);
	if ((stack->max_node && number > stack->max) || (stack->min_node && number < stack->min) || stack->count == 1)
		return (stack->max_node);
	node = stack->head;
	i = 0;
	while (i < stack->count)
	{
		if (number < node->prev->data && number > node->data)
			return (node);
		node = node->next;
		i++;
	}
	return (node);
}
