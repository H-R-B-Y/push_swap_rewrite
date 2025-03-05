/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:09:34 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 00:20:21 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	chunk_is_sorted(t_cdll *stack, size_t sz)
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
