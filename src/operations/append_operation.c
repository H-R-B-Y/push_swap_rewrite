/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:18:03 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/17 13:26:43 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	append_operation_to_list(t_list **p, enum e_op op)
{
	t_list	*node;

	if (op >= OP_COUNT || !p)
		return (0);
	node = ft_lstnew((void *)(unsigned long)op);
	if (!node)
		return (0);
	ft_lstadd_back(p, node);
	return (1);
}

int	append_operation(t_push_swap *meta, enum e_op op)
{
	t_list	*node;

	if (op >= OP_COUNT || !meta)
		return (0);
	// ft_putendl_fd(
	// 	((char *[OP_COUNT + 1]){"PA", "PB", "SA", "SB", "SS", "RA","RB", "RR", "RRA", "RRB", "RRR", "ERR"})[op], 1);
	if (append_operation_to_list(&meta->moves, op))
		return (1);
	return (0);
}
