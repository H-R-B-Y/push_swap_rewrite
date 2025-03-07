/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:26:13 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/07 15:25:26 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	a_micro_sort(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (meta->stack_a->head->data > meta->stack_a->head->next->data)
		sa(meta);
}

void	a_mini_sort(t_push_swap *meta, size_t count)
{
	if (!meta || count < 2 || meta->stack_a->count < 2)
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
		ra(meta);
		a_micro_sort(meta);
		rra(meta);
	}
	a_micro_sort(meta);
}

void	b_micro_sort(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (meta->stack_b->head->data < meta->stack_b->head->next->data)
		sb(meta);
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
		rb(meta);
		b_micro_sort(meta);
		rrb(meta);
	}
	b_micro_sort(meta);
}
