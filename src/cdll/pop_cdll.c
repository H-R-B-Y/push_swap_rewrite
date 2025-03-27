/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_cdll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:36:10 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 16:04:23 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "../../include/libft.h"

static void	calc_check_minmax(t_cdll *list, t_cdll_node *node)
{
	if (list->count == 0)
	{
		list->min_node = 0;
		list->max_node = 0;
		return ;
	}
	if (node == list->max_node)
		cdll_get_max(list);
	if (node == list->min_node)
		cdll_get_min(list);
}

t_cdll_node	*cdll_pop_front(t_cdll *list)
{
	t_cdll_node	*out;

	if (!list || list->count == 0)
		return ((void *)0);
	out = list->head;
	if (list->count > 1)
	{
		list->head = out->next;
		list->head->prev = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		list->head = 0;
		list->tail = 0;
	}
	out->next = 0;
	out->prev = 0;
	list->count--;
	calc_check_minmax(list, out);
	return (out);
}

t_cdll_node	*cdll_pop_back(t_cdll *list)
{
	t_cdll_node	*out;

	if (!list || list->count == 0)
		return ((void *)0);
	out = list->tail;
	if (list->count > 1)
	{
		list->tail = out->prev;
		list->head->prev = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		list->head = 0;
		list->tail = 0;
	}
	out->next = 0;
	out->prev = 0;
	list->count--;
	calc_check_minmax(list, out);
	return (out);
}
