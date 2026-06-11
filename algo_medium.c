/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:05:26 by maminet           #+#    #+#             */
/*   Updated: 2026/06/11 23:32:44 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

Prints the K-Sort thingie of our B stack

void	print_funny(stack *b)
{
	int	i;
	int	ii;

	i = 0;
	while (i < 175)
	{
		printf("-");
		i++;
	}
	printf("\n");
	i = 0;
	ii = 0;
	while (i < b->size)
	{
		ii = 0;
		while (ii - 1 < b->array[i])
		{
			ii++;
			printf("-");
		}
		printf("\n");
		i++;
	}
}*/
void	push_to_b(int is_inside, stack *a, stack *b, int has_rotated)
{
	if (is_inside)
	{
		push(a, b);
		if (b->size >= 2)
		{
			if (!has_rotated)
			{
				rotate(b);
				has_rotated = 1;
			}
			else
				has_rotated = 0;
		}
	}
	else
		rotate(a);
}

void	push_into_b_if_range(stack *a, stack *b, int *sorted_array, int range)
{
	int	i;
	int	ii;
	int	is_inside;
	while (a->size > 0)
	{
		range = ft_sqrt((double)a->size);
		i = 0;
		while (i < a->size)
		{
			sorted_array[i] = a->array[i];
			i++;
		}
		ft_sort_int_tab(sorted_array, i);
		is_inside = 0;
		ii = 0;
		while (ii < range)
		{
			if (a->array[0] == sorted_array[ii])
				is_inside = 1;
			ii++;
		}
		push_to_b(is_inside, a, b, 0);
	}
}

void	push_to_a(int highest, int ii, stack *a, stack *b)
{
	if (ii < b->size / 2)
	{
		while (b->array[0] != highest)
			rotate(b);
		push(b, a);
	}
	else
	{
		while (b->array[0] != highest)
			reverse_rotate(b);
		push(b, a);
	}
}

void	push_highests_to_a(stack *a, stack *b)
{
	int	highest;
	int	i;
	int	ii;

	while (b->size > 0)
	{
		highest = b->array[b->size / 2];
		i = 0;
		ii = 0;
		while (i < b->size)
		{
			if (highest < b->array[i])
			{
				highest = b->array[i];
				ii = i;
			}
			i++;
		}
		ii--;
		push_to_a(highest, ii, a, b);
	}
}

char	*medium_algo(stack *a, stack *b)
{
	int	*sorted_array;

	sorted_array = malloc(sizeof(int) * a->size);
	push_into_b_if_range(a, b, sorted_array, 0);
	push_highests_to_a(a, b);
    free(sorted_array);
}
