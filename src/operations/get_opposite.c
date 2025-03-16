/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opposite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:39:24 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/16 15:08:27 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	get_opposite_operations(enum e_op op)
{
	if (op == PA)
		return (PB);
	else if (op == PB)
		return (PA);
	else if (op == SA)
		return (SA);
	else if (op == SB)
		return (SB);
	else if (op == SS)
		return (SS);
	else if (op == RA)
		return (RRA);
	else if (op == RB)
		return (RRB);
	else if (op == RR)
		return (RRR);
	else if (op == RRA)
		return (RA);
	else if (op == RRB)
		return (RB);
	else if (op == RRR)
		return (RR);
	return (OP_COUNT);
}
