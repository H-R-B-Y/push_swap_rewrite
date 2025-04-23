/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:08:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/23 14:54:04 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// void	sort(t_push_swap *meta)
// {
// 	if (anon_is_sorted(meta, meta->stack_a, meta->stack_a->count))
// 		return ;
// 	if (meta->stack_a->count <= 3)
// 	{
// 		a_mini_sort(meta, meta->stack_a->count);
// 		return ;
// 	}
// 	push_anon(meta, meta->stack_a, meta->stack_b, 0);
// 	push_anon(meta, meta->stack_a, meta->stack_b, 0);
// 	push_anon(meta, meta->stack_a, meta->stack_b, 0);
// 	b_mini_sort(meta, 3);
// 	while (meta->stack_a->count > 3)
// 		b_optimal_push(meta);
// 	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
// 	a_mini_sort(meta, 3);
// 	while (meta->stack_b->count > 0)
// 		a_optimal_push(meta);
// 	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
// 	return ;
// }

void	sort(t_push_swap *meta)
{
	if (anon_is_sorted(meta, meta->stack_a, meta->stack_a->count))
		return ;
	meta->blacklist = find_best_lis(meta, meta->stack_a, &meta->blacklist_size);
	// meta->blacklist = find_lis(meta, meta->stack_a, &meta->blacklist_size);
	// ft_printf("blacklist size is %d\n", meta->blacklist_size);
	while (meta->stack_a->count > meta->blacklist_size
		&& meta->stack_a->count > 5)
	{
		while (node_is_blacklist(meta, meta->stack_a->head))
			ra(meta, 0);
		pb(meta, 0);
	}
	if (meta->stack_a->count == 5 && meta->blacklist_size != 5)
		a_sort_five(meta);
	while (meta->stack_b->count > 0)
		a_optimal_push(meta);
	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
	return ;
}
