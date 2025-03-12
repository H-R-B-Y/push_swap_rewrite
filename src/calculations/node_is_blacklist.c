/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_is_blacklist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:00:55 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/12 17:11:42 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	node_is_blacklist(t_cdll_node *node, t_cdll_node **blacklist)
{
	t_cdll_node	*idx;
	size_t		i;

	if (!node || !blacklist || !*blacklist)
		return (0);
	i = 0;
	while (i == 0 || idx)
	{
		idx = blacklist[i++];
		if (node == idx)
			return (1);
	}
	return (0);
}
