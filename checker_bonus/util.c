/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:48:57 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 16:22:33 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_op_map	*get_op_map(void)
{
	static t_op_map	op_map[12] = {
	{"ra", RA}, {"rra", RRA},
	{"rb", RB}, {"rrb", RRB},
	{"rr", RR}, {"rrr", RRR},
	{"sa", SA}, {"sb", SB},
	{"ss", SS}, {"pa", PA},
	{"pb", PB}, {0, OP_COUNT}};

	return (op_map);
}

int	str_to_op(const char *str)
{
	int			i;
	t_op_map	*map;

	i = 0;
	map = get_op_map();
	while (map[i].op != OP_COUNT)
	{
		if (!ft_strncmp(map[i].str, str, ft_strlen(map[i].str) + 1))
			return (map[i].op);
		i++;
	}
	return (OP_COUNT);
}
