/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:08:48 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/29 15:30:24 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_cdll_node **cdll_arrayify(t_cdll *list, size_t *len)
{
	t_cdll_node	**output;
	t_cdll_node	*i;

	*len = 0;
	if (!list || !len || list->count == 0)
		return ((void *)0);
	output = malloc(sizeof(t_cdll_node *) * (list->count + 1));
	ft_bzero(output, sizeof(t_cdll_node *) * (list->count + 1));
	i = list->head;
	while (*len < list->count)
	{
		output[*len] = i;
		i = i->next;
		(*len)++;
	}
	output[*len] = (void *)0;
	return (output);
}

