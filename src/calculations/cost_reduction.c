/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_reduction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:20:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/26 18:05:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int		ops_are_opposing(enum e_op a, enum e_op b)
{
	if (a == RA && b == RRB)
		return (1);
	if (a == RB && b == RRA)
		return (1);
	if (a == RRA && b == RB)
		return (1);
	if (a == RRB && b == RA)
		return (1);
	return (0);
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

size_t	remove_similar(t_list **ops, enum e_op op, size_t count)
{
	t_list *idx[2];

	idx[0] = (*ops);
	if ((enum e_op)(unsigned long)idx[0]->content != op)
		while (idx[0] && idx[0]->next && (enum e_op)(unsigned long)idx[0]->next->content != op)
			idx[0] = idx[0]->next;
	idx[1] = idx[0]->next;
	while (idx[1] && (enum e_op)(unsigned long)idx[1]->content == op && count)
	{
		idx[0]->next = idx[1]->next;
		free(idx[1]);
		idx[1] = idx[0]->next;
		count--;
	}
	while (count && idx[0] == (*ops) && (enum e_op)(unsigned long)idx[0]->content == op)
	{
		count--;
		(*ops) = idx[0]->next;
		free(idx[0]);
		idx[0] = (*ops);
	}
	return (ft_lstsize(*ops));
}

void	append_similar(t_list **ops, enum e_op op, size_t count)
{
	enum e_op	add;

	if (op == RB || op == RA)
		add = RR;
	else if (op == RRB || op == RRA)
		add = RRR;
	else
		return;
	while (count)
	{
		ft_lstadd_front(ops, ft_lstnew((void *)(unsigned long)add));
		count--;
	}
}

size_t	cost_reduce(t_push_swap *meta, t_list **ops)
{
	enum e_op	op[2];
	size_t		counts[2];
	t_list		*idx;

	(void) meta;
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
	remove_similar(ops, op[0], my_min(counts[0], counts[1]));
	remove_similar(ops, op[1], my_min(counts[0], counts[1]));
	append_similar(ops, op[0], my_min(counts[0], counts[1]));
	return (ft_lstsize(*ops));
}
