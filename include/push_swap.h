/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:14:39 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/25 11:17:12 by hbreeze          ###   ########.fr       */
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

int		append_operation(t_push_swap *meta, enum e_op op);

void	do_ops(t_push_swap *meta, t_list *ops, int silent);
void	_do_op(t_push_swap *meta, enum e_op op, int silent);

void	swap_anon(t_push_swap *meta, t_cdll *stack, int silent);
void	ss(t_push_swap *meta, int silent);
void	sb(t_push_swap *meta, int silent);
void	sa(t_push_swap *meta, int silent);

void	rrot_anon(t_push_swap *meta, t_cdll *stack, int silent);
void	rrr(t_push_swap *meta, int silent);
void	rrb(t_push_swap *meta, int silent);
void	rra(t_push_swap *meta, int silent);

void	rot_anon(t_push_swap *meta, t_cdll *stack, int silent);
void	rr(t_push_swap *meta, int silent);
void	rb(t_push_swap *meta, int silent);
void	ra(t_push_swap *meta, int silent);

void	push_anon(t_push_swap *meta, t_cdll *from, t_cdll *too, int silent);
void	pb(t_push_swap *meta, int silent);
void	pa(t_push_swap *meta, int silent);

int		get_opposite_operations(enum e_op op);

int		parse_args(int argc, char **argv, t_cdll **stack_a);
int		is_valid_int(char *str, int *out);

// this might be a mess
int		find_median_quickselect(t_cdll *stack, size_t count);

void	mini_sort(t_push_swap *meta, t_cdll *st, size_t count);

void	sort(t_push_swap *meta);

// debugmeta
void	print_stack(t_cdll *st);

int		find_median_quickselect(t_cdll *stack, size_t count);


size_t	do_median_split(t_push_swap *meta, t_cdll *st[2],	size_t count, int rotate);

size_t	do_split(t_push_swap *meta, t_cdll *st[2],	size_t count);

void	do_merge(t_push_swap *meta, t_cdll *st[2], size_t count[2]);

void	print_operations(t_push_swap *meta);

int		contains_duplicate(t_cdll *stack);

void	check_swap(t_push_swap *meta, t_cdll *st, size_t sz);

void		rotate_to_top(t_push_swap *meta, t_cdll_node *node, t_cdll *st, size_t count);

long int	distance_from_head(t_cdll *st, t_cdll_node *node, size_t sz);

void	do_a_sort(t_push_swap *meta, size_t count);
void	do_b_sort(t_push_swap *meta, size_t count);
int		anon_is_sorted(t_push_swap *meta, t_cdll *stack, size_t sz);
int		a_chunk_is_sorted(t_cdll *stack, size_t sz);
int		b_chunk_is_sorted(t_cdll *stack, size_t sz);
void	a_micro_sort(t_push_swap *meta);
void	a_mini_sort(t_push_swap *meta, size_t count);
void	b_micro_sort(t_push_swap *meta);
void	b_mini_sort(t_push_swap *meta, size_t count);
void	do_a_merge(t_push_swap *meta, size_t count_a, size_t count_b);
void	do_b_merge(t_push_swap *meta, size_t count_a, size_t count_b);

void	print_stacks(t_push_swap *meta);

t_cdll_node	*b_find_position(t_cdll *stack, int number);
t_cdll_node	*a_find_position(t_cdll *stack, int number);

int		append_operation_to_list(t_list **p, enum e_op op);
size_t	ops_to_top(t_push_swap *meta, t_cdll *st, t_cdll_node *node, t_list **list);

void	do_nothing(void *ptr);



int	a_optimal_push(t_push_swap *meta);
int	b_optimal_push(t_push_swap *meta);

t_cdll_node	**find_cont(t_push_swap *meta, t_cdll *stack);

int	node_is_blacklist(t_cdll_node *node, t_cdll_node **blacklist);

size_t		cost_reduce(t_push_swap *meta, t_list **ops);

void	move_until_sorted(t_push_swap *meta);

/*

Insanity starts here

*/


// /**
//  * @brief descriptor for the most optimal push that will be performed
//  * @param too stack pushing from
//  * @param from stack pushing too
//  * @param to_rots rotations in too 
//  * @param from_rots rotations in from 
//  * @param to_revrots reverse rotations in too
//  * @param from_revrots reverse rotation in from 
//  * 
//  */
// typedef struct s_movedesc {
// 	t_cdll	*too;
// 	t_cdll	*from;
// 	int		to_rots;
// 	int		from_rots;
// 	int		to_revrots;
// 	int		from_revrots;
// }	t_movedesc;

typedef struct s_movedesc	t_movedesc;
struct s_movedesc {
	t_cdll_node	*node;
	t_cdll		*stacks[2];
	t_list		*operations_list;
	size_t		op_count;
	t_movedesc	*next_optimal;
};



#endif