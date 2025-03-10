/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:31:14 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/10 16:35:30 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	do_b_merge(t_push_swap *meta, size_t count_a, size_t count_b)
{
	size_t	i;
	size_t	rots;
	t_cdll_node	*node;
	if (!meta)
		return ;
	print_stacks(meta);
	rots = 0;
	i = 0;
	node = meta->stack_b->head;
	while (meta->stack_b->count && i++ < count_a)
	{
		// while the top of b is greater than the top of a
		// rotate until top of b is less than a
		while (meta->stack_b->head->data > meta->stack_a->head->data && rots < count_b)
		{
			rb(meta);
			print_stacks(meta);
			rots++;
		}
		
		// while bottom of b is < top of a
		// rotate until top of b is less than top of a?
		while (rots && meta->stack_b->tail->data < meta->stack_a->head->data)
		{
			rrb(meta);
			print_stacks(meta);
			rots--;
		}
		pb(meta);
		count_b++;
		if (meta->stack_b->head->data > node->data)
			node = meta->stack_b->head;
	}
	print_stacks(meta);
	rotate_to_top(meta, node, meta->stack_b, i);
}
