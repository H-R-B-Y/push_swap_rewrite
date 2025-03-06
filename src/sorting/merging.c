/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:49:09 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 17:02:35 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/*
st[1] will contain the smaller chunk that needs to be merged back into st[0].
but only between the values at the top.

so count[0] is chunk at top of st[0]
and count[1] is chunk at top of st[1]

we are only allowed to rotate and have to reverse rotate back before returning.

*/
void	_push_loop(t_push_swap *meta, t_cdll *st[2], size_t count[2], size_t *rots)
{
	// Rotate A until B's top element fits correctly
	while (*rots < count[0] &&
		!(st[1]->head->data > st[0]->tail->data ||
		st[1]->head->data < st[0]->head->data))
	{
		rot_anon(meta, st[0]);  // Rotate A
		(*rots)++;  // Track rotations
	}
	// Push B's top element to A
	push_anon(meta, st[1], st[0]);
}

void	do_merge(t_push_swap *meta, t_cdll *st[2], size_t count[2])
{
	size_t	rot_count = 0;
	size_t	idx = 0;
	t_cdll_node	*node;
	long int	rots;

	if (st[0]->head->data < st[1]->head->data)
		node = st[0]->head;
	else
		node = st[1]->head;
	while (count[1] && rot_count < count[0])
	{
		if (st[1]->head->data < st[0]->head->data)
		{
			push_anon(meta, st[1], st[0]);
			count[1]--;
			count[0]++;
			idx++;
			rot_anon(meta, st[0]);
			rot_count++;

		}
		else
		{
			rot_anon(meta, st[0]);
			rot_count++;
		}
	}
	while (count[1])
	{
		push_anon(meta, st[1], st[0]);
		count[1]--;
		count[0]++;
		idx++;
		rot_anon(meta, st[0]);
		rot_count++;
	}
	rotate_to_top(meta, node, st[0], count[0]);
}
