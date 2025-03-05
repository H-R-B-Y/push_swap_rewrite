/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 14:42:52 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	_rev_rotate(t_cdll *st)
{
	if (!st || st->count < 2)
		return (0);
	st->head = st->tail;
	st->tail = st->head->prev;
	return (1);
}

void	rra(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (_rev_rotate(meta->stack_a))
		append_operation(meta, RRA);
}

void	rrb(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (_rev_rotate(meta->stack_b))
		append_operation(meta, RRB);
}

void	rrr(t_push_swap *meta)
{
	int	operation;

	if (!meta)
		return ;
	operation = 0;
	if (meta->stack_a->count > 1 && _rev_rotate(meta->stack_a))
		operation |= RRA;
	if (meta->stack_b->count > 1 && _rev_rotate(meta->stack_b))
		operation |= RRB;
	if (operation == (RRA | RRB))
		append_operation(meta, RRR);
	else if (operation == 0)
		return;
	else
		append_operation(meta, operation);
}

void	rrot_anon(t_push_swap *meta, t_cdll *stack)
{
	if (!meta || !stack)
		return ;
	if (stack == meta->stack_a)
		rra(meta);
	else if (stack == meta->stack_b)
		rrb(meta);
}
