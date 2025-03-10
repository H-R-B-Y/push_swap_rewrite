/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:17:51 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/10 17:23:29 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief recursive sort function
 * @param meta meta contianer for move counts
 * @param st is stack[2] where [0] is a initially and [1] is b (swapped when focusing on b)
 * @param count count of items in current chunk
 */
void	do_b_sort(t_push_swap *meta, size_t count)
{
	size_t	split;
	size_t	i;

	if (!meta)
		return ;
	if (meta->stack_b->count > 0 && !b_chunk_is_sorted(meta->stack_b, count))
	{
		if (count <= 3)
		{
			b_mini_sort(meta, count);
			return ;
		}
		if (count > 10)
			split = do_median_split(meta, (t_cdll *[2]){meta->stack_b, meta->stack_a}, count, count != meta->stack_b->count);
		else
			split = do_split(meta, (t_cdll *[2]){meta->stack_b, meta->stack_a}, count);
		do_b_sort(meta, count - split);
		if (split > 30)
			do_a_sort(meta, split);
		// if (split < 50)
			do_b_merge(meta, split, count - split);
		// if (count - split != meta->stack_b->count)
		// else
			// do_a_merge(meta, split, count - split);
		i = 0;
	}
	return ;
}