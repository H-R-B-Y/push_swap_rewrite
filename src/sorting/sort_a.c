/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:17:51 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/12 14:50:23 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/**
 * @brief recursive sort function
 * @param meta meta contianer for move counts
 * @param st is stack[2] where [0] is a initially and [1] is b (swapped when focusing on b)
 * @param count count of items in current chunk
 */
void	do_a_sort(t_push_swap *meta, size_t count)
{
	size_t	split;
	int		sign;

	if (!meta)
		return ;
	sign = 1 * (meta->stack_b->count == 0);
	if (meta->stack_a->count > 0 && !a_chunk_is_sorted(meta->stack_a, count))
	{
		if (count <= 3)
		{
			a_mini_sort(meta, count);
			return ;
		}
		if (count > 10)
			split = do_median_split(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, count, count != meta->stack_a->count);
		else
			split = do_split(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, count);
		// if (split > 30)
		do_b_sort(meta, split);
		do_a_sort(meta, count - split);
		// if (count != meta->stack_a->count)
		do_a_merge(meta, count - split, split);
	}
	return ;
}