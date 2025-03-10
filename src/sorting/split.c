/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:26:23 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/10 15:30:56 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_swap(t_push_swap *meta, t_cdll *st, size_t sz)
{
	if (sz <= 1)
		return ;
	if (st == meta->stack_a && st->head->data > st->head->next->data)
		swap_anon(meta, st);
	else if (st == meta->stack_b && st->head->data < st->head->next->data)
		swap_anon(meta, st);
}

size_t	do_median_split(t_push_swap *meta, t_cdll *st[2], size_t count, int rotate)
{
	size_t		i[2]; // idx and pushed
	int			median;
	long int	rots;

	median = find_median_quickselect(st[0], count);
	print_stacks(meta);
	ft_bzero(&i, sizeof(size_t) * 2);
	rots = 0;
	while (i[0] < count && i[1] < (count / 2) && ++i[0])
	{
		if (st[0]->head->data < median && ++i[1])
		{
			push_anon(meta, st[0], st[1]);
		}
		else if (++rots)
			rot_anon(meta, st[0]);
		print_stacks(meta);
	}
	while (rotate && rots > 0 && rots != st[0]->count && rots-- )
		{rrot_anon(meta, st[0]);}
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
		
		print_stacks(meta);
		push_anon(meta, st[0], st[1]);
		i++;
	}
	return (max);
}
