/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bcdll.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:02:28 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/19 13:06:52 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BCDLL_H
# define BCDLL_H

typedef struct s_bcdll		t_bcdll;

typedef struct s_bcdll_node	t_bcdll_node;

struct s_bcdll
{
	t_bcdll_node			*head;
	t_bcdll_node			*tail;
	unsigned long int	min;
	unsigned long int	max;
	unsigned long int	count;
	unsigned long int	(*get_bound)(t_bcdll_node *node);
};

struct s_bcdll_node
{
	t_bcdll_node	*next;
	t_bcdll_node	*prev;
	void			*data;
};

t_bcdll	*init_bcdll(unsigned long int (*get_bound)(t_bcdll_node *node));
void	delete_bcdll(t_bcdll	**list);

t_bcdll_node	*init_bcdll_node(int data);
void		delete_bcdll_node(t_bcdll_node **node);

unsigned long int	bcdll_push_front(t_bcdll *list, t_bcdll_node *node);
unsigned long int	bcdll_push_back(t_bcdll *list, t_bcdll_node *node);

t_bcdll_node	*bcdll_pop_front(t_bcdll *list);
t_bcdll_node	*bcdll_pop_back(t_bcdll *list);
t_bcdll_node	*bcdll_pop(t_bcdll *list, t_bcdll_node *node);

#endif