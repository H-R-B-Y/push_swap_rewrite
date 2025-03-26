/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:27:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/26 19:02:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	create_operations_list(t_push_swap *meta, t_cdll *st, t_cdll_node *node, t_list	**ops)
{
	size_t	count;
	t_cdll_node	*under;

	count = ops_to_top(meta, st, node, ops);
	if (st == meta->stack_a)
	{
		under = b_find_position(meta->stack_b, node->data);
		count += ops_to_top(meta, meta->stack_b, under, ops);
		append_operation_to_list(ops, PB);
		count++;
	}
	else
	{
		under = a_find_position(meta->stack_a, node->data);
		count += ops_to_top(meta, meta->stack_a, under, ops);
		append_operation_to_list(ops, PA);
		count++;
	}
	if (count > 2)
		count = cost_reduce(meta, ops);
	return (count);
}

// Push from b to a
// so find best value in b to push to a
void	a_optimal_push(t_push_swap *meta)
{
	t_list	*p[2];
	size_t	p_count[2];
	t_cdll_node	*node;
	size_t	i;

	node = meta->stack_b->head;
	p_count[0] = -1;
	ft_bzero(p, sizeof(t_list *) * 2);
	i = 0;
	while (i < meta->stack_b->count)
	{
		p_count[1] = create_operations_list(meta, meta->stack_b, node, &p[1]);
		if (p_count[1] < p_count[0])
		{
			ft_lstclear(&p[0], (void *)do_nothing);
			p_count[0] = p_count[1];
			p[0] = p[1];
			p[1] = (void *)0;
		}
		else
			ft_lstclear(&p[1], (void *)do_nothing);
		node = node->next;
		i++;
	}
	do_ops(meta, p[0], 0);
	ft_lstclear(&p[0], (void *)do_nothing);
}

// Push from a to b
void	b_optimal_push(t_push_swap *meta)
{
	t_list	*p[2];
	size_t	p_count[2];
	t_cdll_node	*node;
	size_t	i;

	node = meta->stack_a->head;
	p_count[0] = 0;
	p_count[0] -= 1;
	i = 0;
	ft_bzero(p, sizeof(t_list *) * 2);
	while (i < meta->stack_a->count)
	{
		p_count[1] = create_operations_list(meta, meta->stack_a, node, &p[1]);
		if (p_count[1] < p_count[0])
		{
			ft_lstclear(&p[0], (void *)do_nothing);
			p_count[0] = p_count[1];
			p[0] = p[1];
			p[1] = (void *)0;
		}
		else
			ft_lstclear(&p[1], (void *)do_nothing);
		node = node->next;
		i++;
	}
	do_ops(meta, p[0], 0);
	ft_lstclear(&p[0], (void *)do_nothing);
}
