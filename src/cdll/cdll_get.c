/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:07:40 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 14:10:09 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "../../include/libft.h"

t_cdll_node	*cdll_get(t_cdll *stack, size_t i)
{
	t_cdll_node	*tmp;

	if (!stack)
		return ((void *)0);
	tmp = stack->head;
	while (i && --i)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
