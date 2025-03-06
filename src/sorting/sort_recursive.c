/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_recursive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:08:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 16:02:49 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// Recursive do-sort function
// split()
// do-sort split 1
// do-sort split 2
// merge splits
// return

/**
 * @brief recursive sort function
 * @param meta meta contianer for move counts
 * @param st is stack[2] where [0] is a initially and [1] is b (swapped when focusing on b)
 * @param count count of items in current chunk
 */
void	do_sort(t_push_swap *meta, t_cdll *st[2], size_t count)
{
	size_t	split;

	if (!meta || !st)
		return ;

	if (!chunk_is_sorted(st[0], count))
	{
		if (count <= 3)
		{
			mini_sort(meta, st[0], count);
			return ;
		}
		split = do_split(meta, st, count);
		do_sort(meta, (t_cdll *[2]){st[1], st[0]}, split);
		do_sort(meta, st, count - split);
		do_merge(meta, st, (size_t [2]){count - split, split});
	}
	return ;
}

void	sort(t_push_swap *meta)
{
	do_sort(meta,
		(t_cdll *[2]){meta->stack_a, meta->stack_b},
		meta->stack_a->count
	);
}
