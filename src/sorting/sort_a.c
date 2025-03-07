/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:17:51 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/07 16:19:28 by hbreeze          ###   ########.fr       */
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

	if (!meta)
		return ;

	if (!a_chunk_is_sorted(meta->stack_a, count))
	{
		if (count <= 3)
		{
			a_mini_sort(meta, count);
			return ;
		}
		print_stack(meta->stack_a);
		print_stack(meta->stack_b);
		if (count == meta->stack_a->count)
			split = do_median_split(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, count);
		else
			split = do_split(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, count);
		print_stack(meta->stack_a);
		print_stack(meta->stack_b);
		do_b_sort(meta, split);
		do_a_sort(meta, count - split);
		do_a_merge(meta, count - split, split);
		print_stack(meta->stack_a);
		print_stack(meta->stack_b);
	}
	return ;
}