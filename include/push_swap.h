/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:14:39 by hbreeze           #+#    #+#             */
/*   Updated: 2025/04/24 16:24:15 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "cdll.h"

/**
 * @brief Structure to store all the data needed for the push_swap program
 * @param stack_a - stack A
 * @param stack_b - stack B
 * @param moves - list of operations
 * @param move_count - count of operations
 */
typedef struct s_push_swap	t_push_swap;
struct s_push_swap
{
	t_cdll		*stack_a;
	t_cdll		*stack_b;
	t_list		*moves;
	size_t		move_count;
	t_cdll_node	**blacklist;
	size_t		blacklist_size;
};

/**
 * @brief Enum to store all the operations
 * @param PA - push A
 * @param PB - push B
 * @param SA - swap A
 * @param SB - swap B
 * @param SS - swap both
 * @param RA - rotate A
 * @param RB - rotate B
 * @param RR - rotate both
 * @param RRA - reverse rotate A
 * @param RRB - reverse rotate B
 * @param RRR - reverse rotate both
 * @param OP_COUNT - count of operations
 */
enum e_op
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT,
};

/**
 * @brief Function to do nothing
 * @param ptr - pointer to do nothing with
 * @return void
 */
void		do_nothing(void *ptr);

/**
 * @brief Function to sort the stack
 * @param meta - pointer to the structure with all the data
 * @return void
 */
void		sort(t_push_swap *meta, float initial_sort);

/**
 * @brief Rotates a element in the stack to the top
 * @param meta - pointer to the structure with all the data
 * @param node - pointer to the node to rotate
 * @param st - pointer to the stack
 * @return void
 */
void		rotate_to_top(t_push_swap *meta, t_cdll_node *node, t_cdll *st);

/**
 * @brief Counts the operations to rotate the element to the top
 * @param meta - pointer to the structure with all the data
 * @param st - pointer to the stack
 * @param node - pointer to the node to rotate
 * @param list - pointer to the list of operations
 * @return size_t - count of operations
 */
size_t		ops_to_top(t_push_swap *meta, t_cdll *st,
				t_cdll_node *node, t_list **list);

/**
 * @brief Gets the shortest distance to the top of the stack
 * @param st - pointer to the stack
 * @param node - pointer to the node
 * @return long int - distance
 * @note If the distance is negative, the rotations are reversed
 */
long int	distance_from_head(t_cdll *st, t_cdll_node *node);

/**
 * @brief Mini sort stack b (sort < 3 elements)
 * @param meta - pointer to the structure with all the data
 * @param count - count of elements to sort
 * @return void
 */
void		b_mini_sort(t_push_swap *meta, size_t count);

/**
 * @brief Mini sort stack a (sort < 3 elements)
 * @param meta - pointer to the structure with all the data
 * @param count - count of elements to sort
 * @return void
 */
void		a_mini_sort(t_push_swap *meta, size_t count);

/**
 * @brief sorts 5 elements at the top of stack a
 * @param meta the metadata for push swap
 * @returns void
 */
void		a_sort_five(t_push_swap *meta);

/**
 * @brief Check a stack is sorted
 * @param meta - pointer to the structure with all the data
 * @param stack - pointer to the stack
 * @param sz - size of the stack
 * @return int - 1 if sorted, 0 if notFile 'src/sorting/check_sorted.c'
Lines executed:34.38% of 32
 */
int			anon_is_sorted(t_push_swap *meta, t_cdll *stack, size_t sz);

/**
 * @brief Check a chunk of stack b is sorted (Largest to Smallest)
 * @param stack - pointer to the stack
 * @param sz - size of the chunk
 * @return int - 1 if sorted, 0 if not
 */
int			b_chunk_is_sorted(t_cdll *stack, size_t sz);

/**
 * @brief Check a chunk of stack a is sorted (Smallest to Largest)
 * @param stack - pointer to the stack
 * @param sz - size of the chunk
 * @return int - 1 if sorted, 0 if not
 */
int			a_chunk_is_sorted(t_cdll *stack, size_t sz);

/**
 * @brief Parse args from the command line
 * @param argc - count of arguments
 * @param argv - array of arguments
 * @param stack_a - pointer to the stack
 * @return int - 0 if success, 1 if error
 */
int			parse_args(int argc, char **argv, t_cdll **stack_a);

/**
 * @brief Check if a string is a valid integer
 * @param str - string to check
 * @param out - pointer to the integer
 * @return int - 1 if valid, 0 if not
 */
int			is_valid_int(char *str, int *out);

/**
 * @brief Check if a stack contains duplicates
 * @param stack - pointer to the stack
 * @return int - 1 if contains, 0 if not
 */
int			contains_duplicate(t_cdll *stack);

/**
 * @brief Swap the top two elements of a stack
 * @param meta - pointer to the structure with all the data
 * @param stack - pointer to the stack
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		swap_anon(t_push_swap *meta, t_cdll *stack, int silent);

/**
 * @brief Swap top of both stacks
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		ss(t_push_swap *meta, int silent);

/**
 * @brief Swap top of stack b
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		sb(t_push_swap *meta, int silent);

/**
 * @brief Swap top of stack a
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		sa(t_push_swap *meta, int silent);

/**
 * @brief Reverse rotate the stack
 * @param meta - pointer to the structure with all the data
 * @param stack - pointer to the stack
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		rrot_anon(t_push_swap *meta, t_cdll *stack, int silent);

/**
 * @brief Reverse rotate stack a
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		rra(t_push_swap *meta, int silent);

/**
 * @brief Reverse rotate stack b
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		rrb(t_push_swap *meta, int silent);

/**
 * @brief Reverse rotate both stacks
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		rrr(t_push_swap *meta, int silent);

/**
 * @brief Rotate the stack
 * @param meta - pointer to the structure with all the data
 * @param stack - pointer to the stack
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		rot_anon(t_push_swap *meta, t_cdll *stack, int silent);

/**
 * @brief Rotate stack a
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		ra(t_push_swap *meta, int silent);

/**
 * @brief Rotate stack b
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		rb(t_push_swap *meta, int silent);

/**
 * @brief Rotate both stacks
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		rr(t_push_swap *meta, int silent);

/**
 * @brief Push an element from one stack to another
 * @param meta - pointer to the structure with all the data
 * @param from - pointer to the stack to push from
 * @param too - pointer to the stack to push to
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		push_anon(t_push_swap *meta, t_cdll *from, t_cdll *too, int silent);

/**
 * @brief Push an element from stack b to stack a
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		pa(t_push_swap *meta, int silent);

/**
 * @brief Push an element from stack a to stack b
 * @param meta - pointer to the structure with all the data
 * @param silent - 1 if silent, 0 if not
 * @return void
 */
void		pb(t_push_swap *meta, int silent);

/**
 * @brief Get the opposite operation
 * @param op - operation
 * @return int - opposite operation
 * @note if op is not a valid operation, returns OP_COUNT
 */
int			get_opposite_operations(enum e_op op);

/**
 * @brief Do operations from the list
 * @param meta - pointer to the structure with all the data
 * @param ops - pointer to the list of operations
 * @param silent - 1 if silent, 0 if not
 */
void		do_ops(t_push_swap *meta, t_list *ops, int silent);

/**
 * @brief Append an operation to the list
 * @param p - pointer to the list
 * @param op - operation
 * @return int - 0 if success, 1 if error
 */
int			append_operation_to_list(t_list **p, enum e_op op);

/**
 * @brief Append an operation to the list
 * @param meta - pointer to the structure with all the data
 * @param op - operation
 * @return int - 0 if success, 1 if error
 */
int			append_operation(t_push_swap *meta, enum e_op op);

/**
 * @brief Print an operation
 * @param ptr - pointer of operation
 * @return void
 * @note pointer will be cast to enum e_op
 */
void		print_operation(void *ptr);

/**
 * @brief Print all the operations
 * @param meta - pointer to the structure with all the data
 * @return void
 */
void		print_operations(t_push_swap *meta);

/**
 * @brief Min of two numbers
 * @param a - first number
 * @param b - second number
 * @return size_t - min of two numbers
 */
size_t		my_min(size_t a, size_t b);

/**
 * @brief Greedy push from a to b
 * @param meta - pointer to the structure with all the data
 * @return void
 */
void		b_optimal_push(t_push_swap *meta);

/**
 * @brief Greedy push from b to a
 * @param meta - pointer to the structure with all the data
 * @return void
 */
void		a_optimal_push(t_push_swap *meta);

/**
 * @brief Create a list of operations to push an element to the sorted position
 * @param meta - pointer to the structure with all the data
 * @param st - pointer to the stack
 * @param node - pointer to the node
 * @param ops - pointer to the list of operations
 * @return size_t - count of operations
 */
size_t		create_operations_list(t_push_swap *meta, t_cdll *st,
				t_cdll_node *node, t_list	**ops);

/**
 * @brief Find the node containing number in stack a
 * @param stack - pointer to the stack
 * @param number - number to find
 * @return t_cdll_node* - pointer to the node
 */
t_cdll_node	*a_find_position(t_cdll *stack, int number);

/**
 * @brief Find the node containing number in stack b
 * @param stack - pointer to the stack
 * @param number - number to find
 * @return t_cdll_node* - pointer to the node
 */
t_cdll_node	*b_find_position(t_cdll *stack, int number);

/**
 * @brief Check if two operations are opposing
 * @param a - first operation
 * @param b - second operation
 * @return int - 1 if opposing, 0 if not
 * 
 * This is used to check if reduction is possible
 * For example, if a is RA and b is RRA, they are opposing
 * so they cannot be reduced
 * 
 */
int			ops_are_opposing(enum e_op a, enum e_op b);

/**
 * @brief Reduce the cost of the operations
 * @param meta - pointer to the structure with all the data
 * @param ops - pointer to the list of operations
 * @return size_t - count of operations
 * 
 * This function will reduce the cost of the operations
 * For example, if there are two opposing operations, they will be replaced
 * with the corresponding dual operation.
 * 
 * For example, if there are RA and RB, they will be replaced with RR.
 */
size_t		cost_reduce(t_push_swap *meta, t_list **ops);

// LIS

/**
 * @brief Turn a CDLL into an array (not null terminated)
 * @param list the cdll to turn into an array
 * @param len pointer to a variable to store the size of the array.
 */
t_cdll_node	**cdll_arrayify(t_cdll *list, size_t *len);

/**
 * @brief Check if a node is stored in the push swap blacklist
 * @param meta the push swap metadata
 * @param node the node to check
 * @returns 1 if node is blacklisted else 0
 */
int			node_is_blacklist(t_push_swap *meta, t_cdll_node *node);

/**
 * @brief Find the longest increasing sequence of nodes in a stack.
 * @param meta the push swap meta data
 * @param stack the stack to search for the lis
 * @param length pointer to variable to store the size of the lis
 * @returns array of nodes that are part of the lis
 */
t_cdll_node	**find_lis(t_push_swap *meta, t_cdll *stack, size_t	*length);

/**
 * @brief helper function for lis to inisialise the dp and prev arrays
 * @param len the size of the arraysvoid		a_sort_five(t_push_swap *meta);
 * @param dp pointer to the dp array
 * @param prev pointer to the prev array
 */
void		initialise_arrays(size_t len, size_t **dp, long long int **prev);

/**
 * @brief internal function for LIS, populates the dp and prev arrays
 * @param len length of the array to search for lis
 * @param arr pointer to the array of nodes to search
 * @param dp the dp array
 * @param prev the prev array
 */
void		_populate_sizes(size_t len, t_cdll_node **arr,
				size_t *dp, long long int *prev);

/**
 * @brief internal function for LIS, returns address of LIS size
 * @param len the length of the array
 * @param dp the dp array
 * @param prev the prev array
 * @param lislen pointer to variable to store the length of the lis.
 * @returns array index for the dp array storing the lis size
 * 
 * This function sucks, it returns the index of the array elem
 * that contains the lis size, but also takes a variable pointer 
 * to store the size??? whats that about.
 */
size_t		_lis_size_idx(size_t len, size_t *dp, size_t *lislen);

/**
 * @brief finds the best lis and rotates stack into best position
 * @param meta the push swap meta data
 * @param stack the stack to track for lis
 * @param length pointer to variable to store the length of the lis in
 */
t_cdll_node	**find_best_lis(t_push_swap *meta, t_cdll *stack, size_t *length);

// DEBUG
/**
 * @brief Print the stacks
 * @param meta - pointer to the structure with all the data
 * @return void
 */
void		print_stacks(t_push_swap *meta);

/**
 * @brief Print the stack
 * @param st - pointer to the stack
 * @return void
 */
void		print_stack(t_cdll *st);

#endif