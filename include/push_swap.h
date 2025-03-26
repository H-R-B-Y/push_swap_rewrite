/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:14:39 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/26 18:14:29 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "cdll.h"

typedef struct s_push_swap	t_push_swap;
struct s_push_swap
{
	t_cdll		*stack_a;
	t_cdll		*stack_b;
	t_list		*moves;
	size_t		move_count;
};

enum e_op
{
	PA, PB, SA, SB, SS, RA,
	RB, RR, RRA, RRB, RRR,
	OP_COUNT,
};

void		do_nothing(void *ptr);

void		sort(t_push_swap *meta);

void		rotate_to_top(t_push_swap *meta, t_cdll_node *node, t_cdll *st);
size_t		ops_to_top(t_push_swap *meta, t_cdll *st, t_cdll_node *node, t_list **list);
long int	distance_from_head(t_cdll *st, t_cdll_node *node);


void		b_mini_sort(t_push_swap *meta, size_t count);
void		a_mini_sort(t_push_swap *meta, size_t count);

int			anon_is_sorted(t_push_swap *meta, t_cdll *stack, size_t sz);
int			b_chunk_is_sorted(t_cdll *stack, size_t sz);
int			a_chunk_is_sorted(t_cdll *stack, size_t sz);

int			parse_args(int argc, char **argv, t_cdll **stack_a);
int			is_valid_int(char *str, int *out);

int			contains_duplicate(t_cdll *stack);

void	swap_anon(t_push_swap *meta, t_cdll *stack, int silent);
void	ss(t_push_swap *meta, int silent);
void	sb(t_push_swap *meta, int silent);
void	sa(t_push_swap *meta, int silent);

void	rrot_anon(t_push_swap *meta, t_cdll *stack, int silent);
void	rra(t_push_swap *meta, int silent);
void	rrb(t_push_swap *meta, int silent);
void	rrr(t_push_swap *meta, int silent);

void	rot_anon(t_push_swap *meta, t_cdll *stack, int silent);
void	ra(t_push_swap *meta, int silent);
void	rb(t_push_swap *meta, int silent);
void	rr(t_push_swap *meta, int silent);

void	push_anon(t_push_swap *meta, t_cdll *from, t_cdll *too, int silent);
void	pa(t_push_swap *meta, int silent);
void	pb(t_push_swap *meta, int silent);

int		get_opposite_operations(enum e_op op);
void	do_ops(t_push_swap *meta, t_list *ops, int silent);

int	append_operation_to_list(t_list **p, enum e_op op);
int	append_operation(t_push_swap *meta, enum e_op op);

void	print_operation(void *ptr);
void	print_operations(t_push_swap *meta);

size_t	my_min(size_t a, size_t b);

int	b_optimal_push(t_push_swap *meta);
int	a_optimal_push(t_push_swap *meta);
size_t	create_operations_list(t_push_swap *meta, t_cdll *st, t_cdll_node *node, t_list	**ops);

t_cdll_node	*a_find_position(t_cdll *stack, int number);
t_cdll_node	*b_find_position(t_cdll *stack, int number);

int		ops_are_opposing(enum e_op a, enum e_op b);
size_t	cost_reduce(t_push_swap *meta, t_list **ops);

// DEBUG
void	print_stacks(t_push_swap *meta);
void	print_stack(t_cdll *st);

#endif