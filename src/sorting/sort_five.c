/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:08:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/29 12:22:44 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	find_median_quickselect(t_cdll *stack, size_t count);

void	move_something(t_push_swap *meta)
{
	if (my_labs(distance_from_head(meta->stack_a, meta->stack_a->min_node))
		< my_labs(distance_from_head(meta->stack_a, meta->stack_a->max_node)))
		rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
	else
		rotate_to_top(meta, meta->stack_a->max_node, meta->stack_a);
}

void	a_sort_five(t_push_swap *meta)
{
	size_t	ct;
	int		median;
	
	if (meta->stack_a->count <= 3)
	{
		a_mini_sort(meta, meta->stack_a->count);
		return ;
	}
	ct = 0;
	median = find_median_quickselect(meta->stack_a, meta->stack_a->count);
	while (meta->stack_a->count > 3 && !a_chunk_is_sorted(meta->stack_a, meta->stack_a->count))
	{
		if ((meta->stack_a->head->data < median
			|| meta->stack_a->head->data == meta->stack_a->max) && ++ct)
			pb(meta, 0);
		else
			move_something(meta);

	}
	a_mini_sort(meta, 3);
	while (ct--)
		a_optimal_push(meta);
	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
	
}
