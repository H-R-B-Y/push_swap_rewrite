/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:14:39 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/06 00:28:04 by hbreeze          ###   ########.fr       */
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
	t_cdll	*stack_a;
	t_cdll	*stack_b;
	t_list	*moves;
	size_t	move_count;
};

enum e_op
{
	PA, PB, SA, SB, SS, RA,
	RB, RR, RRA, RRB, RRR,
	OP_COUNT,
};

int		append_operation(t_push_swap *meta, enum e_op op);

void	swap_anon(t_push_swap *meta, t_cdll *stack);
void	ss(t_push_swap *meta);
void	sb(t_push_swap *meta);
void	sa(t_push_swap *meta);

void	rrot_anon(t_push_swap *meta, t_cdll *stack);
void	rrr(t_push_swap *meta);
void	rrb(t_push_swap *meta);
void	rra(t_push_swap *meta);

void	rot_anon(t_push_swap *meta, t_cdll *stack);
void	rr(t_push_swap *meta);
void	rb(t_push_swap *meta);
void	ra(t_push_swap *meta);

void	push_anon(t_push_swap *meta, t_cdll *from, t_cdll *too);
void	pb(t_push_swap *meta);
void	pa(t_push_swap *meta);

int		parse_args(int argc, char **argv, t_cdll **stack_a);
int		is_valid_int(char *str, int *out);

// this might be a mess
int		find_median_quickselect(t_cdll *stack, size_t count);

void	mini_sort(t_push_swap *meta, t_cdll *st, size_t count);

void	sort(t_push_swap *meta);

// debug
void	print_stack(t_cdll *st);

int		find_median_quickselect(t_cdll *stack, size_t count);


size_t	do_median_split(t_push_swap *meta, t_cdll *st[2],	size_t count);

size_t	do_split(t_push_swap *meta, t_cdll *st[2],	size_t count);

void	do_merge(t_push_swap *meta, t_cdll *st[2], size_t count[2]);

void	print_operations(t_push_swap *meta);

int		chunk_is_sorted(t_cdll *stack, size_t sz);

int		contains_duplicate(t_cdll *stack);

#endif