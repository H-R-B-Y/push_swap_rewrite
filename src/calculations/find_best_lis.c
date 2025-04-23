/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:08:42 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/23 12:20:41 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

size_t	_get_lis_len(size_t size,
	t_cdll_node **arr,
	size_t *dp,
	long long int *prev
)
{
	size_t	out;

	out = 0;
	_populate_sizes(size, arr, dp, prev);
	_lis_size_idx(size, dp, &out);
	return (out);
}

static void	rotate(t_cdll_node **arr, size_t len)
{
	t_cdll_node	*temp;

	temp = arr[0];
	ft_memmove(arr, &arr[1], len - 2);
	arr[len - 1] = temp;
}

t_cdll_node	*loop_biggest(
	size_t len,
	t_cdll_node **arr,
	size_t *dp,
	long long int *prev
)
{
	size_t		biggest[2];
	size_t		i;
	t_cdll_node	*top[2];

	biggest[1] = 0;
	i = 0;
	top[0] = arr[0];
	while (i < len)
	{
		_populate_sizes(len, arr, dp, prev);
		_lis_size_idx(len, dp, &biggest[0]);
		if (biggest[0] > biggest[1])
		{
			biggest[1] = biggest[0];
			top[1] = top[0];
		}
		rotate(arr, len);
		i++;
		top[0] = arr[0];
	}
	if (biggest[1] < 5)
		return (0);
	return (top[1]);
}

t_cdll_node	**find_best_lis(t_push_swap *meta, t_cdll *stack, size_t *length)
{
	long long int	*prev;
	t_cdll_node		**arr;
	t_cdll_node		*best;
	size_t			*dp;
	size_t			i[2];

	if (!stack || !stack->head)
		return (NULL);
	arr = cdll_arrayify(stack, &i[0]);
	initialise_arrays(i[0], &dp, &prev);
	best = loop_biggest(i[0], arr, dp, prev);
	if (best)
		rotate_to_top(meta, best, stack);
	free(dp);
	free(arr);
	free(prev);
	return (find_lis(meta, stack, length));
}
