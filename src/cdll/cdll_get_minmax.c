/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_get_minmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:48:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/12 14:18:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "../../include/libft.h"

t_cdll_node	*cdll_get_max(t_cdll *stack)
{
	t_cdll_node	*tmp;
	t_cdll_node	*max_node;
	int			max;
	size_t		i;

	if (!stack)
		return ((void *)0);
	max_node = stack->head;
	max = max_node->data;
	tmp = stack->head;
	i = 0;
	while (i < stack->count)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			max_node = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	stack->max = max;
	stack->max_node = max_node;
	return (max_node);
}
t_cdll_node	*cdll_get_min(t_cdll *stack)
{
	t_cdll_node	*tmp;
	t_cdll_node	*min_node;
	int			min;
	size_t		i;

	if (!stack)
		return ((void *)0);
	min_node = stack->head;
	min = min_node->data;
	tmp = stack->head;
	i = 0;
	while (i < stack->count)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_node = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	stack->min = min;
	stack->min_node = min_node;
	return (min_node);
}
