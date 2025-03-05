/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:13:47 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/04 15:22:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static inline void	__swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	quickselect(int *arr, int left, int right, int k)
{
	int	pivot;
	int	i;
	int	j;

	if (left == right)
		return (arr[left]);
	i = left;
	pivot = arr[right];
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
		{
			__swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	__swap(&arr[i], &arr[right]);
	if (i == k)
		return (arr[i]);
	else if (i < k)
		return (quickselect(arr, i + 1, right, k));
	else
		return (quickselect(arr, left, i - 1, k));
}

int	find_median_quickselect(t_cdll *stack, size_t count)
{
	int			*arr;
	t_cdll_node	*node;
	size_t		i;
	int			median;

	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (-1);
	node = stack->head;
	i = 0;
	while (i < count && node)
	{
		arr[i] = node->data;
		node = node->next;
		i++;
	}
	median = quickselect(arr, 0, count - 1, count / 2);
	free(arr);
	return (median);
}
