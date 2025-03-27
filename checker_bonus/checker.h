/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:37:08 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 13:08:58 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../include/push_swap.h"
# include "../include/get_next_line.h"

// # include <fcntl.h>

typedef struct s_op_map	t_op_map;
struct s_op_map {
	const char *str;
	int op;
};

int	str_to_op(const char *str);

#endif 
