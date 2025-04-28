/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_only.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:08:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/28 12:45:29 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// void	sort_three(t_stack **head)
// {
// 	int	biggest;

// 	biggest = find_biggest(*head);
// 	if ((*head)->index == biggest)
// 		rotate_a(head);
// 	else if ((*head)->next->index == biggest)
// 		r_rotate_a(head);
// 	if ((*head)->index > (*head)->next->index)
// 		swap_a(head);
// }

void	a_sort_three_only(t_push_swap *meta, t_cdll	*st)
{
	if (a_chunk_is_sorted(st, meta->stack_a->count))
		return ;
	if (st->head == st->max_node)
		ra(meta, 0);
	else if (st->head->next == st->max_node)
		rra(meta, 0);
	if (st->head->data > st->head->next->data)
		sa(meta, 0);
}
