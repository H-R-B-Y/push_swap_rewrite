/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:46:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/10 13:22:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

void	rotate_to_top(t_push_swap *meta, t_cdll_node *node, t_cdll *st, size_t count)
{
	long int	rots;
	
	rots = distance_from_head(st, node, count);
	while (rots != 0)
	{
		if (rots < 0)
			rot_anon(meta, st);
		else
			rrot_anon(meta, st);
		print_stack(st);
		rots += -1 + (2 * (rots < 0));
	}
}
