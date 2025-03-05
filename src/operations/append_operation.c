/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:03 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 13:24:12 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	append_operation(t_push_swap *meta, enum e_op op)
{
	t_list	*node;

	if (op > OP_COUNT || !meta)
		return (0);
	node = ft_lstnew((void *)((unsigned long)op));
	if (!node)
		return (0);
	ft_lstadd_front(&meta->moves, node);
	return (1);
}
