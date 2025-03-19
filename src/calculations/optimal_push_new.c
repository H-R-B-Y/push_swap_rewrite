/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_push_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:41:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/19 12:49:35 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	create_operations_list(t_push_swap *meta, t_cdll *st, t_cdll_node *node, t_list	**ops);

t_movedesc	*create_move_descriptor(t_push_swap *meta, t_cdll *stacks[2], t_cdll_node *node)
{
	t_movedesc	*move;

	move = malloc(sizeof(t_movedesc));
	ft_bzero(move, sizeof(t_movedesc));
	move->node = node;
	move->stacks[0] = stacks[0];
	move->stacks[1] = stacks[1];
	move->op_count = create_operations_list(meta, stacks[0], node, &move->operations_list);
	move->op_count = ft_lstsize(move->operations_list);
	return (move);
}

void	destroy_move_descriptor(t_movedesc *md)
{
	if (!md)
		return ;
	ft_lstclear(&md->operations_list, (void *)do_nothing);
	free(md);
}

void perform_move_descriptor(t_push_swap *meta, t_movedesc *desc)
{
	// for operation in list
	// do operation
	// (we want to avoid appending the operations to the main operations list)
	// ft_printf("Before MD: ");
	// print_stacks(meta);
	do_ops(meta, desc->operations_list, 1);
	// ft_printf("after MD: ");
	// print_stacks(meta);
}

void undo_move_descriptor(t_push_swap *meta, t_movedesc *desc)
{
	// for operation in list
	// do the OPPOSITE OF THAT OPERATION
	// (we want to avoid appending the operations to the main operations list)
	t_list	*idx[2];
	// ft_printf("restoring MD: ");
	// print_stacks(meta);
	idx[0] = desc->operations_list;
	idx[1] = 0;
	while (idx[1] != desc->operations_list)
	{
		while (idx[0]->next != idx[1])
			idx[0] = idx[0]->next;
		_do_op(meta, get_opposite_operations((enum e_op)(unsigned long)idx[0]->content), 1);
		idx[1] = idx[0];
		idx[0] = desc->operations_list;
	}
	// ft_printf("restored MD: ");
	// print_stacks(meta);
}

void	collapse_move_descriptor(t_movedesc *md)
{
	if (!md || !md->next_optimal)
		return ;
	ft_lstlast(md->operations_list)->next = md->next_optimal->operations_list;
	md->next_optimal->operations_list = 0;
	md->op_count += md->next_optimal->op_count;
	destroy_move_descriptor(md->next_optimal);
	return ;
}

t_movedesc	*anon_optimal_push(t_push_swap *meta, t_cdll *stacks[2], size_t depth, t_movedesc *parent)
{
	t_list		*potentials[2];
	size_t		i;
	t_cdll_node	*node;
	t_movedesc	*current;

	if (depth == 0 || !stacks || !meta)
		return (0);
	if (parent)
		perform_move_descriptor(meta, parent);
	if (anon_is_sorted(meta, stacks[0], stacks[0]->count))
	{
		undo_move_descriptor(meta, parent);
		return (0);
	}
	node = stacks[0]->head;
	ft_memset(potentials, 0, sizeof(t_list *) * 2);
	i = 0;
	// loop through all nodes (except blacklisted)
	while (i < stacks[0]->count)
	{
		if (!node_is_blacklist(node, meta->blacklist))
		{
			// create a move descriptor
			current = create_move_descriptor(meta, stacks, node);
			// if the move descriptor is shorter than the smallest
			// 	delete all potentials
			// 	add this move descriptor to the potentials
			// if the move descriptor is longer than the smallest
			// 	delete it
			// if the move desciptor is the same length add it to the potentials
			if (!potentials[0] || current->op_count < ((t_movedesc *)potentials[0]->content)->op_count)
			{
				ft_lstclear(&(potentials[0]), (void *)&destroy_move_descriptor);
				ft_lstadd_back(&(potentials[0]), ft_lstnew(current));
			}
			else if (potentials[0] && current->op_count == ((t_movedesc *)potentials[0]->content)->op_count)
				ft_lstadd_back(&(potentials[0]), ft_lstnew(current));
			else
				destroy_move_descriptor(current);
		}
		node = node->next;
		i++;
	}
	// for each move descriptor
	potentials[1] = potentials[0];
	current = 0;
	while (potentials[1])
	{
		((t_movedesc *)potentials[1]->content)->next_optimal = anon_optimal_push(meta, stacks, depth - 1, (t_movedesc *)potentials[1]->content);
		collapse_move_descriptor((t_movedesc *)potentials[1]->content);
		if (!current || current->op_count > ((t_movedesc *)potentials[1]->content)->op_count)
			current = (t_movedesc *)potentials[1]->content; 
		potentials[1] = potentials[1]->next;
	}
	// find the potential with the smallest combined score
	potentials[1] = potentials[0];
	while (potentials[1])
	{
		if ((t_movedesc *)potentials[1]->content == current)
			potentials[1]->content = 0;
		potentials[1] = potentials[1]->next;
	}
	ft_lstclear(&potentials[0], (void *)destroy_move_descriptor);
	if (parent)
		undo_move_descriptor(meta, parent);
	return (current);
}

static inline size_t my_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

void	move_until_sorted(t_push_swap *meta)
{
	t_movedesc	*desc;

	while ((!a_chunk_is_sorted(meta->stack_a, meta->stack_a->count)) && meta->stack_a->count > meta->black_list_count)
	{
		desc = anon_optimal_push(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, 
		5, 0);
		if (!desc)
		{while (meta->stack_a->count > meta->black_list_count)
			b_optimal_push(meta);
		return;}
		ft_printf("Optimal push found length: %d\n", desc->op_count);
		do_ops(meta, desc->operations_list, 0);
		destroy_move_descriptor(desc);
	}
	return ;
}
