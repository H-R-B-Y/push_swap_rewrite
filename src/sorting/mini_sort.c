/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:26:13 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 14:47:14 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	micro_sort(t_push_swap *meta, t_cdll *st)
{
	if (!meta || !st)
		return ;
	if (st->head->data > st->head->next->data)
		swap_anon(meta, st);
}

void	mini_sort(t_push_swap *meta, t_cdll *st, size_t count)
{
	if (!meta || !st || count < 2 || st->count < 2)
		return ;
	if (count == 2)
	{
		micro_sort(meta, st);
		return ;
	}
	micro_sort(meta, st);
	if (st->head->next->data > st->head->next->next->data)
	{
		rot_anon(meta, st);
		micro_sort(meta, st);
		rrot_anon(meta, st);
	}
	micro_sort(meta, st);
}
