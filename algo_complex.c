/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:05:26 by maminet           #+#    #+#             */
/*   Updated: 2026/06/11 18:01:08 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	bring_me_to_the_top_con(stack *a, int smallest, int smallest_index)
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
char	*complex_algo(stack *a, stack *b){
    
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
		bring_me_to_the_top_con(a, smallest, smallest_index);
		push(a, b);
	}
	while (b->size > 0)
		push(b, a);
}