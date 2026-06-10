/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:53:07 by maminet           #+#    #+#             */
/*   Updated: 2026/06/10 17:52:56 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	fill_values(stack *stack, int is_a, int size_array)
{
	stack->p = 0;
	stack->r = 0;
	stack->rr = 0;
	stack->rrr = 0;
	stack->rrrr = 0;
	stack->s = 0;
	stack->ss = 0;
	stack->is_a = is_a;
	if (is_a)
		stack->size = size_array;
	else
		stack->size = 0;
	stack->array = malloc(sizeof(int) * size_array);
}

stack	*create_stack(int is_a, int size_array, int arg_index, char **argv)
{
	int		i;
	stack	*staack;

	staack = malloc(sizeof(stack));
	fill_values(staack, is_a, size_array);
	if (!is_a)
		return (staack);
	i = 0;
	while (i < size_array)
	{
		staack->array[i] = ft_atoi(argv[arg_index]);
		arg_index++;
		i++;
	}
	return (staack);
}

ps_struct *create_struc(stack *stack_a, stack *stack_b, char **argv, int size_array){
    
    ps_struct *struc;
	struc = malloc(sizeof(ps_struct));
	struc->stack_a = stack_a;
	struc->stack_b = stack_b;
	struc->benchie = check_arg(1, argv);
	struc->disorder = calculate_disorder(stack_a->array, size_array);
	struc->strategy = check_arg(0, argv);
    
    return struc;
}
