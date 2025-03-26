/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_push_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 12:41:00 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/26 18:07:29 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
	while (i < stacks[0]->count)
	{
		current = create_move_descriptor(meta, stacks, node);
		if (!potentials[0] || current->op_count < ((t_movedesc *)potentials[0]->content)->op_count)
		{
			ft_lstclear(&(potentials[0]), (void *)&destroy_move_descriptor);
			ft_lstadd_back(&(potentials[0]), ft_lstnew(current));
		}
		else if (potentials[0] && current->op_count == ((t_movedesc *)potentials[0]->content)->op_count)
			ft_lstadd_back(&(potentials[0]), ft_lstnew(current));
		else
			destroy_move_descriptor(current);
		node = node->next;
		i++;
	}
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

void	move_until_sorted(t_push_swap *meta)
{
	t_movedesc	*desc;

	while ((!a_chunk_is_sorted(meta->stack_a, meta->stack_a->count)) && meta->stack_a->count > 3)
	{
		desc = anon_optimal_push(meta, (t_cdll *[2]){meta->stack_a, meta->stack_b}, 
		1, 0);
		if (!desc)
		{
			while (meta->stack_a->count > 3)
				b_optimal_push(meta);
			return;
		}
		do_ops(meta, desc->operations_list, 0);
		destroy_move_descriptor(desc);
	}
	return ;
}
