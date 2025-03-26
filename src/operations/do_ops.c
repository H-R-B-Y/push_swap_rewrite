/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:13:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/16 13:38:37 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	_do_op(t_push_swap *meta, enum e_op op, int silent)
{
	if (!meta || op >= OP_COUNT)
		return ;
	if (op == PA)
		pa(meta, silent);
	else if (op == PB)
		pb(meta, silent);
	else if (op == SA)
		sa(meta, silent);
	else if (op == SB)
		sb(meta, silent);
	else if (op == SS)
		ss(meta, silent);
	else if (op == RA)
		ra(meta, silent);
	else if (op == RB)
		rb(meta, silent);
	else if (op == RR)
		rr(meta, silent);
	else if (op == RRA)
		rra(meta, silent);
	else if (op == RRB)
		rrb(meta, silent);
	else if (op == RRR)
		rrr(meta, silent);
}

void	do_ops(t_push_swap *meta, t_list *ops, int silent)
{
	if (!meta || !ops)
		return ;
	while (ops)
	{
		_do_op(meta, (enum e_op)(unsigned long)ops->content, silent);
		ops = ops->next;
	}
	return ;
}
