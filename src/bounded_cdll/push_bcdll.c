/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bcdll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:27:55 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/19 13:11:07 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcdll.h"
#include "../../include/libft.h"

unsigned long int	bcdll_push_front(t_bcdll *list, t_bcdll_node *node)
{
	if (!list || !node)
		return (0);
	if (list->count)
	{
		node->next = list->head;
		list->head->prev = node;
		node->prev = list->tail;
		list->tail->next = node;
		list->head = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
		list->head = node;
		list->tail = node;
	}
	list->count++;
	return (list->count);
}

unsigned long int	bcdll_push_back(t_bcdll *list, t_bcdll_node *node)
{
	if (!list || !node)
		return (0);
	if (list->count)
	{
		node->next = list->head;
		list->head->prev = node;
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
	else
	{
		node->next = node;
		node->prev = node;
		list->head = node;
		list->tail = node;
	}
	list->count++;
	return (list->count);
}
