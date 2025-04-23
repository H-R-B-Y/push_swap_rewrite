/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:42:20 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/21 17:33:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	my_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

t_cdll_node	**cdll_arrayify(t_cdll *list, size_t *len)
{
	t_cdll_node	**output;
	t_cdll_node	*i;

	if (!list || !len || list->count == 0)
		return ((void *)0);
	*len = 0;
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
