/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:46:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/17 12:15:54 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static inline long int m_abs(long int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

long int	distance_from_head(t_cdll *st, t_cdll_node *node, size_t sz)
{
	t_cdll_node	*i;
	long int	back;
	long int	forth;

	if (!st || !node || node == st->head)
		return (0);
	i = node->next;
	forth = 1;
	while(i != st->head)
	{
		i = i->next;
		forth++;
	}
	back = st->count - forth;
	if (forth > back)
		return (-back);
	else
		return (forth);
}

size_t	ops_to_top(t_push_swap *meta, t_cdll *st, t_cdll_node *node, t_list **list)
{
	long int	rots;
	long int	output;
	int			offset;
	

	rots = distance_from_head(st, node, 0);
	output = rots;
	offset = 1 * (st == meta->stack_b);
	while (rots != 0)
	{
		if (rots < 0)
			append_operation_to_list(list, RA + offset);
		else
			append_operation_to_list(list, RRA + offset);
		rots += -1 + (2 * (rots < 0));
	}
	return	(m_abs(output));
}

void	rotate_to_top(t_push_swap *meta, t_cdll_node *node, t_cdll *st, size_t count)
{
	long int	rots;
	
	rots = distance_from_head(st, node, count);
	while (rots != 0)
	{
		if (rots < 0)
			rot_anon(meta, st, 0);
		else
			rrot_anon(meta, st, 0);
		// print_stack(st);
		rots += -1 + (2 * (rots < 0));
	}
}
