/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 15:20:49 by hbreeze          ###   ########.fr       */
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

void	ra(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (_rotate(meta->stack_a))
		append_operation(meta, RA);
}

void	rb(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (_rotate(meta->stack_b))
		append_operation(meta, RB);
}

void	rr(t_push_swap *meta)
{
	int	operation;

	if (!meta)
		return ;
	operation = 0;
	if (meta->stack_a->count > 1 && _rotate(meta->stack_a))
		operation |= RA;
	if (meta->stack_b->count > 1 && _rotate(meta->stack_b))
		operation |= RB;
	if (operation == (RA | RB))
		append_operation(meta, RR);
	else if (operation == 0)
		return;
	else
		append_operation(meta, operation);
}

void	rot_anon(t_push_swap *meta, t_cdll *stack)
{
	if (!meta || !stack)
		return ;
	if (stack == meta->stack_a)
		ra(meta);
	else if (stack == meta->stack_b)
		rb(meta);
}
