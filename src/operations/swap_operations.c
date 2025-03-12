/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/12 14:27:43 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	_swap(t_cdll *st)
{
	t_cdll_node temp;

	if (!st || st->count < 2)
		return (0);
	temp.data = st->head->data;
	st->head->data = st->head->next->data;
	st->head->next->data = temp.data;
	if (st->head->data == st->min)
		st->min_node = st->head;
	else if (st->head->next->data == st->min)
		st->min_node = st->head->next;
	if (st->head->data == st->max)
		st->max_node = st->head;
	else if (st->head->next->data == st->max)
		st->max_node = st->head->next;
	return (1);
}

void	sa(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (_swap(meta->stack_a))
		append_operation(meta, SA);
}

void	sb(t_push_swap *meta)
{
	if (!meta)
		return ;
	if (_swap(meta->stack_b))
		append_operation(meta, SB);
}

// this isnt great if one of the swap statement fails for some reason
// it could potentially perform multiple swaps
void	ss(t_push_swap *meta)
{
	int	operation;

	if (!meta)
		return ;
	operation = 0;
	if (meta->stack_a->count > 1 && _swap(meta->stack_a))
		operation |= SA;
	if (meta->stack_b->count > 1 && _swap(meta->stack_b))
		operation |= SB;
	if (operation == (SA | SB))
		append_operation(meta, SS);
	else if (operation == 0)
		return;
	else
		append_operation(meta, operation);
}

void	swap_anon(t_push_swap *meta, t_cdll *stack)
{
	if (!meta || !stack)
		return ;
	if (stack == meta->stack_a)
		sa(meta);
	else if (stack == meta->stack_b)
		sb(meta);
}
