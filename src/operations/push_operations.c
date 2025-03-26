/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/16 13:36:09 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	_push(t_cdll *from, t_cdll *too)
{
	t_cdll_node	*node;

	if (!from || !too)
		return (0);
	node = cdll_pop_front(from);
	if (!node)
		return (0);
	cdll_push_front(too, node);
	return (1);
}
/*
From B to A
*/

void	pa(t_push_swap *meta, int silent)
{
	if (!meta)
		return ;
	if (_push(meta->stack_b, meta->stack_a) && !silent)
		append_operation(meta, PA);
}

void	pb(t_push_swap *meta, int silent)
{
	if (!meta)
		return ;
	if (_push(meta->stack_a, meta->stack_b) && !silent)
		append_operation(meta, PB);
}

void	push_anon(t_push_swap *meta, t_cdll *from, t_cdll *too, int silent)
{
	if (!meta || !from || !too)
		return ;
	if (from == meta->stack_a)
		pb(meta, silent);
	else if (from == meta->stack_b)
		pa(meta, silent);
}
