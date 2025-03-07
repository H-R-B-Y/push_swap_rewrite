/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:15:09 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 14:38:44 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static inline void	do_nothing(void *ptr)
{
	(void)ptr;
}

int main(int argc, char **argv, char **env)
{
	t_push_swap	meta;

	if (argc < 2)
		return (1);
	ft_bzero(&meta, sizeof(t_push_swap));
	meta.stack_a = init_cdll();
	if (parse_args(argc - 1, argv + 1, &meta.stack_a))
	{
		delete_cdll(&(meta.stack_a));
		return (1);
	}
	meta.stack_b = init_cdll();
	// ft_printf("stack is sorted: %s\n", 
	// (char *[2]){"no", "yes"}[chunk_is_sorted(meta.stack_a, meta.stack_a->count)]);
	// ft_printf("stack contains duplicate: %s\n", 
	// (char *[2]){"no", "yes"}[contains_duplicate(meta.stack_a)]);
	sort(&meta);
	ft_printf("stack is sorted: %s\n", 
	(char *[2]){"no", "yes"}[chunk_is_sorted(meta.stack_a, meta.stack_a->count)]);
	print_stack(meta.stack_a);
	ft_printf("stack is sorted: %s\n\n", 
	(char *[2]){"no", "yes"}[chunk_is_sorted(meta.stack_a, meta.stack_a->count)]);
	print_operations(&meta);
	delete_cdll(&(meta.stack_a));
	delete_cdll(&(meta.stack_b));
	ft_lstclear(&(meta.moves), &do_nothing);
	return (0);
}
