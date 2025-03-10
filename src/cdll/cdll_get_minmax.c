/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_get_minmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:48:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/10 16:52:22 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "../../include/libft.h"

t_cdll_node	*cdll_get_max(t_cdll *stack)
{
	t_cdll_node	*tmp;
	t_cdll_node	*max_node;
	int			max;

	if (!stack)
		return ((void *)0);
	max = stack->head->data;
	tmp = stack->head;
	while (tmp->next != stack->head)
	{
		if (tmp->data > max)
		{
			max = tmp->data;
			max_node = tmp;
		}
		tmp = tmp->next;
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

	if (!stack)
		return ((void *)0);
	min = stack->head->data;
	tmp = stack->head;
	while (tmp->next != stack->head)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	stack->min = min;
	stack->min_node = min_node;
	return (min_node);
}
