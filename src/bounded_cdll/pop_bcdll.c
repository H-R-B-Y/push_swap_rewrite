/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_bcdll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:36:10 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/19 13:10:26 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcdll.h"
#include "../../include/libft.h"

t_bcdll_node	*cdll_pop_front(t_bcdll *list)
{
	t_bcdll_node	*out;

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
	return (out);
}

t_bcdll_node	*cdll_pop_back(t_bcdll *list)
{
	t_bcdll_node	*out;

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
	return (out);
}

t_bcdll_node	*bcdll_pop(t_bcdll *list, t_bcdll_node *node)
{
	(void)list;
	(void)node;
}
