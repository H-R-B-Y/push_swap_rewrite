/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:27:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/13 15:13:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	create_operations_list(t_push_swap *meta, t_cdll *st, t_cdll_node *node, t_list	**ops)
{
	size_t	count;
	t_cdll_node	*under;

	count = ops_to_top(meta, st, node, ops);
	if (st == meta->stack_a) // Pushing from stack a to stack b
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

t_list	*find_optimal_push_for_nodes(t_push_swap *meta, t_cdll *st, t_cdll_node **nodes)
{
	t_list		*p[2];
	size_t		p_count[2];
	t_cdll		*opposite;
	t_cdll_node	*idx;

	if (st == meta->stack_a)
		opposite = meta->stack_b;
	else
		opposite = meta->stack_a;
	p_count[0] = -1;
	ft_bzero(p, sizeof(t_list *) * 2);
	idx = nodes[0];
	while (idx)
	{
		p_count[1] = create_operations_list(meta, opposite, idx, &p[1]);
		if (p_count[1] < p_count[0])
		{
			ft_lstclear(&p[0], (void *)do_nothing);
			p_count[0] = p_count[1];
			p[0] = p[1];
			p[1] = (void *)0;
		}
		else
			ft_lstclear(&p[1], (void *)do_nothing);
		idx++;
	}
	return (p[0]);
}

// Push from b to a
// so find best value in b to push to a
int	a_optimal_push(t_push_swap *meta)
{
	t_list	*p[2]; // actual vs temp;
	size_t	p_count[2]; // actual vs temp;
	t_cdll_node	*node;
	size_t	i;

	// for each item in b;
	node = meta->stack_b->head;
	p_count[0] = 0;
	p_count[0] -= 1;
	ft_bzero(p, sizeof(t_list *) * 2);
	i = 0;print_stacks(meta);
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
	// and need to perform the actual operations
	do_ops(meta, p[0]);
	print_stacks(meta);
	ft_lstclear(&p[0], (void *)do_nothing);
	return (1);
}

// Push from a to b
int	b_optimal_push(t_push_swap *meta)
{
	t_list	*p[2]; // actual vs temp;
	size_t	p_count[2]; // actual vs temp;
	t_cdll_node	*node;
	size_t	i;

	// for each item in a;
	node = meta->stack_a->head;
	p_count[0] = 0;
	p_count[0] -= 1;
	i = 0;
	ft_bzero(p, sizeof(t_list *) * 2);
	while (i < meta->stack_a->count)
	{
		if (node_is_blacklist(node, meta->blacklist))
		{
			node = node->next;
			i++;
			continue ;
		}
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
	// and need to perform the actual operations
	if (ft_lstsize(p[0]) > 0)
	{
		do_ops(meta, p[0]);
		print_stacks(meta);
		ft_lstclear(&p[0], (void *)do_nothing);
		return (1);
	}
	else
	{
		ft_lstclear(&p[0], (void *)do_nothing);
		return (0);
	}
}
