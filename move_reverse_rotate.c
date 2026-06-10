/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:16:29 by maminet           #+#    #+#             */
/*   Updated: 2026/06/10 17:53:24 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(stack *staack)
{
	if (!staack->struc->benchie)
	{
		if (staack->is_a)
			printf("rra\n");
		else
			printf("rrb\n");
	}
	action_reverse_rotate(staack);
}

void	action_reverse_rotate(stack *staack)
{
	int	temp;
	int	i;

	if (staack->size < 1)
		return ;
	temp = staack->array[staack->size - 1];
	i = staack->size;
	while (i > 0)
	{
		staack->array[i] = staack->array[i - 1];
		i--;
	}
	staack->array[0] = temp;
	staack->rrr++;
}

void	reverse_rotate_reverse_rotate(stack *stack_a, stack *stack_b)
{
	action_reverse_rotate(stack_a);
	action_reverse_rotate(stack_b);
	stack_a->rrrr++;
	stack_a->rrr--;
	stack_b->rrr--;
	if (!stack_a->struc->benchie)
		printf("rrr\n");
}
