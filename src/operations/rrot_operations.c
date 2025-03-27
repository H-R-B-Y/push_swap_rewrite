/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 16:06:50 by hbreeze          ###   ########.fr       */
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

void	rra(t_push_swap *meta, int silent)
{
	if (!meta)
		return ;
	if (_rev_rotate(meta->stack_a) && !silent)
		append_operation(meta, RRA);
}

void	rrb(t_push_swap *meta, int silent)
{
	if (!meta)
		return ;
	if (_rev_rotate(meta->stack_b) && !silent)
		append_operation(meta, RRB);
}

void	rrr(t_push_swap *meta, int silent)
{
	int	operation;

	if (!meta)
		return ;
	operation = 0;
	if (meta->stack_a->count > 1 && _rev_rotate(meta->stack_a))
		operation |= RRA;
	if (meta->stack_b->count > 1 && _rev_rotate(meta->stack_b))
		operation |= RRB;
	if (!silent)
	{
		if (operation == (RRA | RRB))
			append_operation(meta, RRR);
		else if (operation == 0)
			return ;
		else
			append_operation(meta, operation);
	}
}

void	rrot_anon(t_push_swap *meta, t_cdll *stack, int silent)
{
	if (!meta || !stack)
		return ;
	if (stack == meta->stack_a)
		rra(meta, silent);
	else if (stack == meta->stack_b)
		rrb(meta, silent);
}
