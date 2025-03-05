/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_cdll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:36:10 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/03 15:42:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "../../include/libft.h"

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
	return (out);
}
