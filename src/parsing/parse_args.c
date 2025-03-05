/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:59:44 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 00:02:23 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_valid_int(char *str, int *out)
{
	long int	i;
	int			sign;
	int			limit;

	sign = 1;
	i = 0;
	limit = 2147483647;
	while (*str && ft_iswhitespace(*str))
		str++;
	while (*str && ft_strchr("-+", *str))
		sign *= 1 - 2 * (*str++ == '-');
	if (sign == -1)
		limit = 2147483648;
	while (*str && ft_strchr("0123456789", *str))
	{
		if (i > (limit - (*str - '0')) / 10)
			return (0);
		i = i * 10 + (*str++ - '0');
	}
	if (*str)
		return (0);
	*out = (int)(i * sign);
	return (1);
}

int	parse_args(int argc, char **argv, t_cdll **stack_a)
{
	int	data;

	if (!(*stack_a))
		return (1);
	while(argc)
	{
		if (!is_valid_int(argv[argc - 1], &data))
			return (2);
		if (!cdll_push_front(*stack_a, init_node(data)))
			return (4);
		argc--;
	}
	return (0);
}
