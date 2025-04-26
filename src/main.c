/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:15:09 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/26 17:13:52 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_quick_start(t_push_swap *meta, float initial_sort);
void	push_back(t_push_swap *meta);

void	redo(t_push_swap *meta, int argc, char **argv)
{
	float	start;

	start = 1.2;
	while (start < 2.1 && meta->move_count >= 5500)
	{
		delete_cdll(&(meta->stack_a));
		ft_lstclear(&(meta->moves), &do_nothing);
		meta->stack_a = init_cdll();
		parse_args(argc - 1, argv + 1, &meta->stack_a);
		meta->move_count = 0;
		sort_quick_start(meta, start);
		push_back(meta);
		start += 0.05;
		meta->move_count = ft_lstsize(meta->moves);
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	meta;

	if (argc < 2)
		return (1);
	ft_bzero(&meta, sizeof(t_push_swap));
	meta.stack_a = init_cdll();
	if (parse_args(argc, argv + 1, &meta.stack_a)
		|| contains_duplicate(meta.stack_a))
	{
		ft_putendl_fd("Error", 2);
		delete_cdll(&(meta.stack_a));
		return (1);
	}
	meta.stack_b = init_cdll();
	sort(&meta, 0.25);
	meta.move_count = ft_lstsize(meta.moves);
	if (meta.move_count > 5500 && meta.stack_a->count == 500)
		redo(&meta, argc, argv);
	print_operations(&meta);
	delete_cdll(&(meta.stack_a));
	delete_cdll(&(meta.stack_b));
	free(meta.blacklist);
	ft_lstclear(&(meta.moves), &do_nothing);
	return (0);
}
