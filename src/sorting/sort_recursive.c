/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:08:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 12:24:48 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort(t_push_swap *meta)
{
	if (anon_is_sorted(meta, meta->stack_a, meta->stack_a->count))
		return ;
	if (meta->stack_a->count <= 3)
	{
		a_mini_sort(meta, meta->stack_a->count);
		return ;
	}
	push_anon(meta, meta->stack_a, meta->stack_b, 0);
	push_anon(meta, meta->stack_a, meta->stack_b, 0);
	push_anon(meta, meta->stack_a, meta->stack_b, 0);
	b_mini_sort(meta, 3);
	while (meta->stack_a->count > 3)
		b_optimal_push(meta);
	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
	a_mini_sort(meta, 3);
	while (meta->stack_b->count > 0)
		a_optimal_push(meta);
	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
	return ;
}
