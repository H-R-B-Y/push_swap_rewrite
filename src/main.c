/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:15:09 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 15:57:30 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	meta;

	if (argc < 2)
		return (1);
	ft_bzero(&meta, sizeof(t_push_swap));
	meta.stack_a = init_cdll();
	if (parse_args(argc - 1, argv + 1, &meta.stack_a)
		|| contains_duplicate(meta.stack_a))
	{
		ft_putendl_fd("Error", 2);
		delete_cdll(&(meta.stack_a));
		return (1);
	}
	meta.stack_b = init_cdll();
	sort(&meta);
	print_operations(&meta);
	delete_cdll(&(meta.stack_a));
	delete_cdll(&(meta.stack_b));
	ft_lstclear(&(meta.moves), &do_nothing);
	return (0);
}
