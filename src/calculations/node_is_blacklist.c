/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_is_blacklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:00:55 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/29 17:36:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	node_is_blacklist(t_push_swap *meta, t_cdll_node *node)
{
	t_cdll_node	*idx;
	size_t		i;

	if (!node || !meta)
		return (0);
	i = 0;
	while (i < meta->blacklist_size)
	{
		idx = meta->blacklist[i];
		if (idx == node)
			return (1);
		i++;
	}
	return (0);
}
