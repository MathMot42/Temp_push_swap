/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:16:29 by maminet           #+#    #+#             */
/*   Updated: 2026/06/11 17:51:33 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(stack *staack)
{
		if (staack->is_a)
			write(1,"sa\n",3);
		else
			write(1,"sb\n",3);
	
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
// 1
// bench = 2
void	swapswap(stack *stack_a, stack *stack_b)
{
	action_swap(stack_a);
	action_swap(stack_b);
	stack_a->ss++;
	stack_a->s--;
	stack_b->s--;
		write(1,"ss\n",3);
}
