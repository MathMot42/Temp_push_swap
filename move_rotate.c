/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:16:29 by maminet           #+#    #+#             */
/*   Updated: 2026/06/10 17:53:15 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(stack *staack)
{
	if (!staack->struc->benchie)
	{
		if (staack->is_a)
			printf("ra\n");
		else
			printf("rb\n");
	}
	action_rotate(staack);
}

void	action_rotate(stack *staack)
{
	int	temp;
	int	i;

	if (staack->size < 1)
		return ;
	temp = staack->array[0];
	i = 0;
	while (i < staack->size)
	{
		staack->array[i] = staack->array[i + 1];
		i++;
	}
	staack->array[staack->size - 1] = temp;
	staack->r++;
}

void	rotaterotate(stack *stack_a, stack *stack_b)
{
	action_rotate(stack_a);
	action_rotate(stack_b);
	stack_a->rr++;
	stack_a->r--;
	stack_b->r--;
	if (!stack_a->struc->benchie)
		printf("rr\n");
}
