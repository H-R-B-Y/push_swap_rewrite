/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:26:13 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/28 12:33:46 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	a_sort_three_only(t_push_swap *meta, t_cdll	*st);

void	a_micro_sort(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (meta->stack_a->head->data > meta->stack_a->head->next->data)
		sa(meta, 0);
}

void	a_mini_sort(t_push_swap *meta, size_t count)
{
	if (!meta || count < 2 || meta->stack_a->count < 2)
		return ;
	if (meta->stack_a->count == 3)
		a_sort_three_only(meta, meta->stack_a);
	if (a_chunk_is_sorted(meta->stack_a, count))
		return ;
	if (count == 2)
	{
		a_micro_sort(meta);
		return ;
	}
	a_micro_sort(meta);
	if (meta->stack_a->head->next->data
		> meta->stack_a->head->next->next->data)
	{
		ra(meta, 0);
		a_micro_sort(meta);
		rra(meta, 0);
	}
	a_micro_sort(meta);
}

void	b_micro_sort(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (meta->stack_b->head->data < meta->stack_b->head->next->data)
		sb(meta, 0);
}

void	b_mini_sort(t_push_swap *meta, size_t count)
{
	if (!meta || count < 2 || meta->stack_b->count < 2)
		return ;
	if (count == 2)
	{
		b_micro_sort(meta);
		return ;
	}
	b_micro_sort(meta);
	if (meta->stack_b->head->next->data
		< meta->stack_b->head->next->next->data)
	{
		rb(meta, 0);
		b_micro_sort(meta);
		rrb(meta, 0);
	}
	b_micro_sort(meta);
}
