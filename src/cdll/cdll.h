/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdll.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:28 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 15:21:32 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDLL_H
# define CDLL_H

typedef struct s_cdll		t_cdll;

typedef struct s_cdll_node	t_cdll_node;

struct s_cdll
{
	t_cdll_node			*head;
	t_cdll_node			*tail;
	unsigned long int	count;
};

struct s_cdll_node
{
	t_cdll_node	*next;
	t_cdll_node	*prev;
	int			data;
};

t_cdll	*init_cdll();
void	delete_cdll(t_cdll	**list);

t_cdll_node	*init_node(int data);
void		delete_node(t_cdll_node **node);

unsigned long int	cdll_push_front(t_cdll *list, t_cdll_node *node);
unsigned long int	cdll_push_back(t_cdll *list, t_cdll_node *node);

t_cdll_node	*cdll_pop_front(t_cdll *list);
t_cdll_node	*cdll_pop_back(t_cdll *list);

t_cdll_node	*cdll_get(t_cdll *stack, unsigned long i);

#endif