/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:08:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/24 16:27:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"


size_t	create_operations_list(t_push_swap *meta, t_cdll *st,
		t_cdll_node *node, t_list	**ops);

void	sort_quick_start(t_push_swap *meta, float initial_sort)
{
	size_t	sz;

	sz = meta->stack_a->count;
	while (meta->stack_a->count > meta->blacklist_size
		&& meta->stack_a->count > 5)
	{
		while (node_is_blacklist(meta, meta->stack_a->head))
			ra(meta, 0);
		if (initial_sort > 0 && (meta->stack_a->count - meta->blacklist_size
			> (sz - meta->blacklist_size) / initial_sort)
			&& meta->stack_b->count > 2)
			b_optimal_push(meta);
		else
			pb(meta, 0);
	}
}

void	push_back(t_push_swap *meta)
{
	if (meta->stack_a->count == 5 && meta->blacklist_size != 5)
		a_sort_five(meta);
	while (meta->stack_b->count > 0)
		a_optimal_push(meta);
	rotate_to_top(meta, meta->stack_a->min_node, meta->stack_a);
}

void	sort(t_push_swap *meta, float initial_sort)
{

	if (anon_is_sorted(meta, meta->stack_a, meta->stack_a->count))
		return ;
	meta->blacklist = find_best_lis(meta, meta->stack_a, &meta->blacklist_size);
	sort_quick_start(meta, initial_sort);
	push_back(meta);
	return ;
}
