/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:08:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/23 12:08:52 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	a_sort_five(t_push_swap *meta)
{
	if (meta->stack_a->count <= 3)
	{
		a_mini_sort(meta, meta->stack_a->count);
		return ;
	}
	if (a_chunk_is_sorted(meta->stack_a, 5))
		return ;
	a_mini_sort(meta, 3);
	if (a_chunk_is_sorted(meta->stack_a, 5))
		return ;
	rra(meta, 0);
	rra(meta, 0);
	a_mini_sort(meta, 3);
	if (a_chunk_is_sorted(meta->stack_a, 5))
		return ;
	ra(meta, 0);
	ra(meta, 0);
	a_mini_sort(meta, 3);
}
