/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:08:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/29 15:29:50 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Recursive do-sort function
// split()
// do-sort split 1
// do-sort split 2
// merge splits
// return

t_cdll_node	**find_lis(t_cdll *stack);

void	sort(t_push_swap *meta)
{
	

	// meta->blacklist = find_cont(meta->stack_a);
	meta->blacklist = find_lis(meta->stack_a);
	// size_t	split;

	// if (meta->stack_a->count <= 3)
	// {
	// 	a_mini_sort(meta, meta->stack_a->count);
	// 	return ;
	// }
	// split = do_median_split(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, meta->stack_a->count, 0);
	// // split = do_split(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, meta->stack_a->count);
	// do_a_sort(meta, meta->stack_a->count);
	// do_b_sort(meta, split);
	// do_a_merge(meta, split)
	// while (meta->stack_b->count > 0)
	// 	a_optimal_push(meta);
	// rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a, meta->stack_a->count);

	// normal
	// do_a_sort(meta, meta->stack_a->count);
	
	// test greedy insertion
	push_anon(meta, meta->stack_a, meta->stack_b);
	push_anon(meta, meta->stack_a, meta->stack_b);
	push_anon(meta, meta->stack_a, meta->stack_b);
	b_mini_sort(meta, 3);
	while (!(meta->stack_a->count < 3) && !(a_chunk_is_sorted(meta->stack_a, meta->stack_a->count)))
	{
		if (!b_optimal_push(meta))
			break ;
	}

	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a, meta->stack_a->count);
	// while (meta->stack_b->count > 0)
	// 	pa(meta);
	a_mini_sort(meta, 3);
	while (meta->stack_b->count > 0)
		a_optimal_push(meta);
	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a, meta->stack_a->count);
	return ;
}
