/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:31:14 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/07 16:46:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	do_b_merge(t_push_swap *meta, size_t count_a, size_t count_b)
{
	size_t	i;
	size_t	rots;
	if (!meta)
		return ;
	rots = 0;
	i = 0;
	while (i++ < count_a)
	{
		while (meta->stack_b->head->data > meta->stack_a->head->data && rots++ < count_b)
			{rb(meta);print_stacks(meta);}
		while (rots && meta->stack_b->tail->data < meta->stack_a->head->data && rots--)
			{rrb(meta);print_stacks(meta);}
		pb(meta);
		count_b++;
	}
	while (rots && rots--)
		{rrb(meta);print_stacks(meta);}
}
