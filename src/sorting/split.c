/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:26:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 16:05:54 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_swap(t_push_swap *meta, t_cdll *st, size_t sz)
{
	if (sz > 1 && st->head->data > st->head->next->data)
		swap_anon(meta, st);
}

size_t	do_median_split(t_push_swap *meta, t_cdll *st[2],	size_t count)
{
	size_t		i[2]; // idx and pushed
	int			median;
	long int	rots;

	median = find_median_quickselect(st[0], count);
	ft_bzero(&i, sizeof(size_t) * 2);
	rots = 0;
	while (i[0] < count && i[1] < count / 2)
	{
		if (st[0]->head->data < median)
		{
			push_anon(meta, st[0], st[1]);
			i[1]++;
			if (i[1] > 1 & st[1]->head->data > st[1]->head->next->data)
				swap_anon(meta, st[1]);
		}
		else
		{
			rot_anon(meta, st[0]);
			rots++;
		}
		i[0]++;
		print_stack(st[0]);
		print_stack(st[1]);
		ft_putendl_fd("", 1);
	}
	while (rots && rots--)
	{
		rrot_anon(meta, st[0]);
		print_stack(st[0]);
	}
	return (i[1]);
}

size_t	do_split(t_push_swap *meta, t_cdll *st[2],	size_t count)
{
	size_t	max;
	size_t	i;

	max = count / 2;
	i = 0;
	while (i < max)
	{
		
		push_anon(meta, st[0], st[1]);
		i++;
		// if (i > 1 && st[1]->head->data > st[1]->head->next->data)
		// 	swap_anon(meta, st[1]);
	}
	return (max);
}
