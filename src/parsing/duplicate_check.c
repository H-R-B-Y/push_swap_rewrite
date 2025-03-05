/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:22:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 00:32:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// returns true IF ANY DUPLICATES EXIST
int	contains_duplicate(t_cdll *stack)
{
	t_cdll_node *idx[2];

	if (!stack)
		return (0);
	idx[0] = stack->head;
	while (idx[0] && idx[0] != stack->tail->prev)
	{
		idx[1] = idx[0]->next;
		while (idx[1] && idx[1] != stack->head)
		{
			if (idx[0]->data == idx[1]->data)
				return (1);
			idx[1] = idx[1]->next;
		}
		idx[0] = idx[0]->next;
	}
	return (0);
}
