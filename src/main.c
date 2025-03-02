/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbreeze <hbreeze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:15:09 by hbreeze           #+#    #+#             */
/*   Updated: 2025/03/02 20:05:17 by hbreeze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
Sort will happen in two intertwined phases

	divide the stack
	focus on stack b first
	keep dividing until you reach a division that has 2 / 3 items
	sort both divisions
	merge the divisions
	then look at the next divison

so stack goes like:
7
3
6
1
18
5
9
11
14

median is 7 so:
a		b
18		7
9		3
11		6
14		1
		5

divide again
A		B
3		7
1		6
5
18
9
11
14

sort two divions:
A		B
5		7
3		6
1
18
9
11
14

merge back:
A		B
18		7
9		6
11		5
14		3
		1

divide again:
A		B
9		18
11		14
		7
		6
		5
		3
		1

sort:
A		B
9		14
11		18
		7
		6
		5
		3
		1

merge:
A		B
9		7
11		6
14		5
18		3
		1

merge back:
1
3
5
6
7
9
11
14
18

Note that all substacks of b sort in reverse order of stack a?
this might not be needed I will have to figure that out

I want this to be a recursive function (division)

	if (size < 4) {
		sort_base_case(size);  // Sort small chunks directly
		return;
	}
	int half = size / 2;
	// Move half of `a` to `b`
	move_to_b(half);
	// Recursively sort the first half (now in `b`)
	sort_stack(half);
	// Recursively sort the second half (remaining in `a`)
	sort_stack(size - half);
	// Merge sorted halves back into `a`
	merge_sorted_chunks(size, half);
*/


int main(int argc, char **argv, char **env)
{
	if (argc < 2)
		return (0);
	// validate and parse inputs
	// if not validate or parse failed
	//	return (1);
	// any other data prep
	// sort(data);
	return (0);
}
