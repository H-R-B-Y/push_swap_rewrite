/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_opperations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:26:17 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 16:06:26 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_operation(void *ptr)
{
	enum e_op	op;

	op = (int)(unsigned long)ptr;
	ft_printf("%s\n", ((char *[OP_COUNT]){
			"pa", "pb", "sa", "sb", "ss", "ra",
			"rb", "rr", "rra", "rrb", "rrr"
		})[op]);
}

void	print_operations(t_push_swap *meta)
{
	ft_lstiter(meta->moves, (void *)(&print_operation));
}
