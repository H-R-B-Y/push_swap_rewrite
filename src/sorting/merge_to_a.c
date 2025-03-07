/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:31:14 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/07 16:18:24 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	do_a_merge(t_push_swap *meta, size_t count_a, size_t count_b)
{
	size_t	i;
	size_t	rots;
	if (!meta)
		return ;
	rots = 0;
	i = 0;
	while (i++ < count_b)
	{
		while (meta->stack_a->head->data < meta->stack_b->head->data && rots++ < count_a)
			ra(meta);
		while (rots && meta->stack_a->tail->data > meta->stack_b->head->data && rots--)
			rra(meta);
		pa(meta);
		count_a++;
	}
	while (rots && rots--)
		rra(meta);
}
