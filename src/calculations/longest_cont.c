/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_cont.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:27:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/29 15:21:02 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t		_cont_len(t_cdll *stack, t_cdll_node *node)
{
	size_t	arr_len;
	t_cdll_node	*idx[2];

	if (node->data > node->next->data)
		return (0);
	idx[0] = node->next;
	idx[1] = node->next->next;
	arr_len = 2;
	while (idx[1] != node
	&& idx[0]->data < idx[1]->data)
	{
		arr_len++;
		idx[0] = idx[1];
		idx[1] = idx[1]->next;
	}
	return (arr_len);
}

t_cdll_node	*_find_arr(t_cdll *stack, size_t *len)
{
	size_t		i;
	size_t		max[2]; // current vs max max
	t_cdll_node	*max_node;
	t_cdll_node	*node;

	i = 0;
	ft_bzero(max, sizeof(size_t) * 2);
	max_node = 0;
	node = stack->head;
	while (i == 0 || node != stack->head)
	{
		max[0] = _cont_len(stack, node);
		if (!max_node || max[0] > max[1])
		{
			max_node = node;
			max[1] = max[0];
		}
		node = node->next;
		i++;
	}
	*len = max[1];
	return (max_node);
}

t_cdll_node	**find_cont(t_cdll *stack)
{
	t_cdll_node	**node_arr;
	t_cdll_node	*start;
	size_t		arr_len;
	size_t		i;

	start = _find_arr(stack, &arr_len);
	node_arr = malloc(sizeof(t_cdll_node) * (arr_len + 1));
	node_arr[arr_len] = (void *)0;
	i = 0;
	while (i < arr_len)
	{
		node_arr[i] = start;
		start = start->next;
		i++;
	}
	return (node_arr);
}
