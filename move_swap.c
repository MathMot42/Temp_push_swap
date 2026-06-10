/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:16:29 by maminet           #+#    #+#             */
/*   Updated: 2026/06/10 15:21:18 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(stack *staack)
{
	if (!staack->struc->benchie)
	{
		if (staack->is_a)
			printf("sa\n");
		else
			printf("sb\n");
	}
	action_swap(staack);
}

void	action_swap(stack *staack)
{
	int	temp;

	if (staack->size < 2)
		return ;
	temp = staack->array[0];
	staack->array[0] = staack->array[1];
	staack->array[1] = temp;
	staack->s++;
}

void	swapswap(stack *stack_a, stack *stack_b)
{
	action_swap(stack_a);
	action_swap(stack_b);
	stack_a->ss++;
	stack_a->s--;
	stack_b->s--;
	if (!stack_a->struc->benchie)
		printf("ss\n");
}
