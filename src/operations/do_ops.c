/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/12 12:23:55 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	_do_op(t_push_swap *meta, enum e_op op)
{
	if (!meta || op >= OP_COUNT)
		return ;
	if (op == PA)
		pa(meta);
	else if (op == PB)
		pb(meta);
	else if (op == SA)
		sa(meta);
	else if (op == SB)
		sb(meta);
	else if (op == SS)
		ss(meta);
	else if (op == RA)
		ra(meta);
	else if (op == RB)
		rb(meta);
	else if (op == RR)
		rr(meta);
	else if (op == RRA)
		rra(meta);
	else if (op == RRB)
		rrb(meta);
	else if (op == RRR)
		rrr(meta);
}

void	do_ops(t_push_swap *meta, t_list *ops)
{
	if (!meta || !ops)
		return ;
	while (ops)
	{
		_do_op(meta, (enum e_op)(unsigned long)ops->content);
		ops = ops->next;
	}
	return ;
}
