/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bcdll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:16 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/19 13:08:51 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bcdll.h"
#include "../../include/libft.h"

t_bcdll_node	*init_bcdll_node(int data)
{
	t_bcdll_node	*node;

	node = malloc(sizeof(t_bcdll_node));
	if (!node)
		return ((void *)0);
	ft_bzero(node, sizeof(t_bcdll_node));
	node->data = data;
	return (node);
}

void	delete_bcdll_node(t_bcdll_node **node)
{
	if (!node || !*node)
		return ;
	free(*node);
	*node = 0;
}

t_bcdll	*init_cdll(unsigned long int (*get_bound)(t_bcdll_node *node))
{
	t_bcdll	*list;

	list = malloc(sizeof(t_bcdll));
	if (!list)
		return ((void *)0);
	ft_bzero(list, sizeof(t_bcdll));
	list->get_bound = get_bound;
	return (list);
}

void	delete_cbdll(t_bcdll	**list)
{
	t_bcdll_node	*tmp;
	t_bcdll_node	*node;

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
