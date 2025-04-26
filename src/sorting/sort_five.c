/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:08:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/26 17:17:35 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"



// Need to re-implement this code:

/*
void	sort_three(t_stack **head)
{
	int	biggest;

	biggest = find_biggest(*head);
	if ((*head)->index == biggest)
		rotate_a(head);
	else if ((*head)->next->index == biggest)
		r_rotate_a(head);
	if ((*head)->index > (*head)->next->index)
		swap_a(head);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = count_nodes(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	radix
*/


void	a_sort_five(t_push_swap *meta)
{
	if (meta->stack_a->count <= 3)
	{
		a_mini_sort(meta, meta->stack_a->count);
		return ;
	}
	if (a_chunk_is_sorted(meta->stack_a, 5))
		return ;
	a_mini_sort(meta, 3);
	if (a_chunk_is_sorted(meta->stack_a, 5))
		return ;
	ra(meta, 0);
	ra(meta, 0);
	a_mini_sort(meta, 3);
	if (a_chunk_is_sorted(meta->stack_a, 5))
		return ;
	rra(meta, 0);
	a_mini_sort(meta, 3);
	if (a_chunk_is_sorted(meta->stack_a, 5))
		return ;
	rra(meta, 0);
	a_mini_sort(meta, 3);
}
