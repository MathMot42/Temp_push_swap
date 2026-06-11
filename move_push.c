/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:16:29 by maminet           #+#    #+#             */
/*   Updated: 2026/06/11 22:04:34 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(stack *staack_from, stack *staack_to)
{

		if (staack_from->is_a)
			write(1,"pb\n",3);
		else
			write(1,"pa\n",3);
	
	action_push(staack_from, staack_to);
}

//                  _
// ARC DE TRIOMPHE | |
void	action_push(stack *staack_from, stack *staack_to)
{
	int	i;

	if (staack_from->size < 1)
		return ;
	i = staack_to->size;
	while (i > 0)
	{
		staack_to->array[i] = staack_to->array[i - 1];
		i--;
	}
	staack_to->size++;
	staack_to->array[0] = staack_from->array[0];
	i = 0;
	while (i < staack_from->size-1)
	{
		staack_from->array[i] = staack_from->array[i + 1];
		i++;
	}
	staack_from->size--;
	staack_to->p++;
}

void	pushpush(stack *stack_a, stack *stack_b)
{
	push(stack_a, stack_b);
	push(stack_b, stack_a);
}
