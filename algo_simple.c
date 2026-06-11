/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:51:02 by maminet           #+#    #+#             */
/*   Updated: 2026/06/11 16:13:20 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Gets the smallest element + its index in the array, and then
rotate/reverse rotate depending on its original position
to get it to the top, so then later on it can be pushed
to the other stack
*/

void	bring_me_to_the_top(stack *a, int smallest, int smallest_index)
{
	if (smallest_index < a->size / 2)
	{
		while (a->array[0] != smallest)
			rotate(a);
	}
	else
	{
		while (a->array[0] != smallest)
			reverse_rotate(a);
	}
}

/*
First, we find the smallest value of the stack a
Then, we bring the item to the top, by either rotate until it's on top
only if its index is less than the size of the array divided by two
or if it's not, spamming reverse rotate until it's on the last position
to then swap to get it on top
We then push it to stack B
and over again until stack a is empty
now, we're left with stack b, order à l'envers du plus grand
au plus petit
And finally, we spam push from B to A so that
Stack A has an orderly list (rangé quoi dans l'ordre croissant)
*/
char	*simple_algo(stack *a, stack *b)
{
	int	i;
	int	smallest;
	int	smallest_index;

	if (is_sort(a))
		return ("\n");
	while (a->size > 0)
	{
		i = 0;
		smallest = a->array[0];
		smallest_index = 0;
		while (i < a->size)
		{
			if (a->array[i] < smallest)
			{
				smallest = a->array[i];
				smallest_index = i;
			}
			i++;
		}
		bring_me_to_the_top(a, smallest, smallest_index);
		push(a, b);
	}
	while (b->size > 0)
		push(b, a);
}
