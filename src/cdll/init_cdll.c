/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cdll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 00:04:28 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cdll.h"
#include "../../include/libft.h"

t_cdll_node	*init_node(int data)
{
	t_cdll_node	*node;

	node = malloc(sizeof(t_cdll_node));
	if (!node)
		return ((void *)0);
	ft_bzero(node, sizeof(t_cdll_node));
	node->data = data;
	return (node);
}

void	delete_node(t_cdll_node **node)
{
	if (!node || !*node)
		return ;
	free(*node);
	*node = 0;
}

t_cdll	*init_cdll()
{
	t_cdll	*list;

	list = malloc(sizeof(t_cdll));
	if (!list)
		return ((void *)0);
	ft_bzero(list, sizeof(t_cdll));
	return (list);
}

void	delete_cdll(t_cdll	**list)
{
	t_cdll_node	*tmp;
	t_cdll_node	*node;

	if (!list || !*list)
		return ;
	tmp = (*list)->head;
	while (tmp && tmp != (*list)->tail)
	{
		node = tmp->next;
		delete_node(&tmp);
		tmp = node;
	}
	delete_node(&tmp);
	free(*list);
	return ;
}
