/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 16:07:19 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	_rotate(t_cdll *st)
{
	if (!st || st->count < 2)
		return (0);
	st->tail = st->head;
	st->head = st->tail->next;
	return (1);
}

void	ra(t_push_swap *meta, int silent)
{
	if (!meta)
		return ;
	if (_rotate(meta->stack_a) && !silent)
		append_operation(meta, RA);
}

void	rb(t_push_swap *meta, int silent)
{
	if (!meta)
		return ;
	if (_rotate(meta->stack_b) && !silent)
		append_operation(meta, RB);
}

void	rr(t_push_swap *meta, int silent)
{
	int	operation;

	if (!meta)
		return ;
	operation = 0;
	if (meta->stack_a->count > 1 && _rotate(meta->stack_a))
		operation |= RA;
	if (meta->stack_b->count > 1 && _rotate(meta->stack_b))
		operation |= RB;
	if (!silent)
	{
		if (operation == (RA | RB))
			append_operation(meta, RR);
		else if (operation == 0)
			return ;
		else
			append_operation(meta, operation);
	}
}

void	rot_anon(t_push_swap *meta, t_cdll *stack, int silent)
{
	if (!meta || !stack)
		return ;
	if (stack == meta->stack_a)
		ra(meta, silent);
	else if (stack == meta->stack_b)
		rb(meta, silent);
}
