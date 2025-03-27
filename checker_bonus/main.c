/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:38:25 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/27 13:52:56 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	append_all_ops(t_push_swap *meta)
{
	char	*str;
	enum e_op	op;

	str = get_next_line(STDIN_FILENO);
	while (str)
	{
		if (ft_strchr(str, '\n'))
			*(ft_strchr(str, '\n')) = '\0';
		op = str_to_op(str);
		if (op >= OP_COUNT || op < 0)
		{
			ft_lstclear(&meta->moves, do_nothing);
			free(str);
			return (0);
		}
		append_operation(meta, op);
		free(str);
		str = get_next_line(STDIN_FILENO);
	}
	free(str);
	return (1);
}
static int cleanup(t_push_swap *meta, int code, char *str)
{
	delete_cdll(&meta->stack_a);
	delete_cdll(&meta->stack_b);
	ft_lstclear(&meta->moves, do_nothing);
	ft_putendl_fd(str, 1 + (1 * (code != 0)));
	return (code);
}

int main(int argc, char **argv)
{
	t_push_swap	meta;
	size_t		sz;

	
	if (argc < 2)
		return (1);
	ft_bzero(&meta, sizeof(t_push_swap));
	meta.stack_a = init_cdll();
	if (parse_args(argc - 1, argv + 1, &meta.stack_a)
		|| contains_duplicate(meta.stack_a))
		return (cleanup(&meta, 1, "ERROR"));
	sz = meta.stack_a->count;
	meta.stack_b = init_cdll();
	if (!append_all_ops(&meta))
		return (cleanup(&meta, 1, "ERROR"));
	do_ops(&meta, meta.moves, 1);
	if (meta.stack_a->count != sz || !a_chunk_is_sorted(meta.stack_a, meta.stack_a->count))
		return (cleanup(&meta, 0, "KO"));
	return (cleanup(&meta, 0, "OK"));
}
