/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:26:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 16:47:25 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	do_median_split(t_push_swap *meta, t_cdll *st[2],	size_t count)
{
	size_t	i[2]; // idx and pushed
	int		median;

	median = find_median_quickselect(st[0], count);
	ft_bzero(&i, sizeof(int) * 2);
	while (i[0] < count && i[1] < count / 2)
	{
		if (st[0]->head->data < median)
		{
			push_anon(meta, st[0], st[1]);
			i[1]++;
		}
		else
			rot_anon(meta, st[0]);
		i[0]++;
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
	}
	return (max);
}
