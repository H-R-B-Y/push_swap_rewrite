/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:08:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/29 16:21:30 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_cdll_node **cdll_arrayify(t_cdll *list, size_t *len);

static void	initialise_arrays(size_t len, size_t **dp, size_t **prev)
{
	size_t	i;

	i = 0;
	*dp = malloc(sizeof(size_t) * len);
	while (i < len)
	{
		(*dp)[i] = 1;
		i++;
	}
	*prev = malloc(sizeof(size_t) * len);
	ft_bzero((*prev), sizeof(size_t) * len);
}

static size_t	_lis_size_idx(size_t len, size_t *dp, size_t *prev)
{
	size_t	idx;
	size_t	lis_len;
	size_t	lis_idx;

	idx = 0;
	lis_len = 0;
	while (idx < len)
	{
		if (dp[idx] > lis_len)
		{
			lis_len = dp[idx];
			lis_idx = idx;
		}
		idx++;
	}
	return (lis_idx);
}

static t_cdll_node	**_build_lis(size_t len, t_cdll_node **arr, size_t *dp, size_t *prev)
{
	size_t	idx[2];
	t_cdll_node	**lis;

	idx[0] = 1;
	while (idx[0] < len)
	{
		idx[1] = 0;
		while (idx[1] < idx[0])
		{
			if (arr[idx[0]]->data > arr[idx[1]]->data)
			{
				if (dp[idx[0]] < (dp[idx[1]] + 1))
				{
					dp[idx[0]] = dp[idx[1]] + 1;
					prev[idx[0]] = idx[1];
				}
			}
			idx[1]++;
		}
		idx[0]++;
	}
	idx[0] = _lis_size_idx(len, dp, prev);
	lis = malloc(sizeof(t_cdll_node *) * dp[idx[0]]);
	idx[1] = dp[idx[0]] - 1; // now the size of the array;
	while (idx[1] > 0)
	{
		lis[idx[1]] = arr[idx[0]];
		idx[0] = prev[idx[0]];
		idx[1]--;
	}
	lis[idx[1]] = arr[idx[0]];
	return (lis);
}

t_cdll_node	**find_lis(t_cdll *stack)
{
	size_t		len;
	size_t		*dp;
	size_t		*prev;
	t_cdll_node	**arr;
	t_cdll_node	**lis;

	if (!stack || !stack->head)
		return (NULL);
	arr = cdll_arrayify(stack, &len);
	initialise_arrays(len, &dp, &prev);
	lis = _build_lis(len, arr, dp, prev);
	free(dp);
	free(prev);
	return (lis);
}
