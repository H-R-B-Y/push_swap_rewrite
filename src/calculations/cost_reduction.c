/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_reduction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:20:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/13 13:49:07 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		ops_are_opposing(enum e_op a, enum e_op b)
{
	if (a == RA || a == RB)
		if (b == RRA || RRB)
			return (1);
	if (a == RRB || a == RRB)
		if (b == RA || b == RB)
			return (1);
	return (0);
}

static inline size_t	ul_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

size_t	count_similar(t_list *p, enum e_op a)
{
	size_t	count;

	count = 0;
	while (p && (enum e_op)(unsigned long)p->content == a)
	{
		count++;
		p = p->next;
	}
	return (count);
}

size_t remove_similar(t_list **ops, enum e_op op, size_t count)
{
	t_list	*idx[2];

	idx[0] = (*ops);
	while (idx[0] && idx[0]->next && (enum e_op)(unsigned long)idx[0]->next->content != op)
		idx[0] = idx[0]->next;
	idx[1] == idx[0]->next;
	while (idx[1] && (enum e_op)(unsigned long)idx[1]->content == op && count)
	{
		idx[0]->next = idx[1]->next;
		free(idx[1]);
		idx[1] = idx[0]->next;
		count--;
	}
	if (count && idx[0] == (*ops) && (enum e_op)(unsigned long)idx[0]->next->content == op)
	{
		count--;
		(*ops) = idx[0]->next;
		free(idx[0]);
	}
	return (ft_lstsize(*ops));
}

size_t	cost_reduce(t_push_swap *meta, t_list **ops)
{
	enum e_op	op[2];
	size_t		counts[2];
	t_list		*idx;

	op[0] = (enum e_op)(unsigned long)(*ops)->content;
	if (op[0] == PA || op[0] == PB)
		return (0);
	idx = (*ops);
	while (idx && (enum e_op)(unsigned long)idx->content == op[0])
			idx = idx->next;
	op[1] = (enum e_op)(unsigned long)idx->content;
	if (op[1] == PA || op[1] == PB || ops_are_opposing(op[0], op[1]))
		return (ft_lstsize(*ops));
	counts[0] = count_similar((*ops), op[0]);
	counts[1] = count_similar(idx, op[1]);
	counts[0] = ul_min(counts[0], counts[1]);
	remove_similar(ops, op[0], counts[0]);
	remove_similar(ops, op[1], counts[1]);
	
}
