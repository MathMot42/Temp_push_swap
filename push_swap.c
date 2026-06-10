/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:54:50 by maminet           #+#    #+#             */
/*   Updated: 2026/06/10 16:02:01 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int size_array, char **argv, int arg_index)
{
	stack		*stack_a;
	stack		*stack_b;
	ps_struct	*struc;

	stack_a = create_stack(1, size_array, arg_index, argv);
	stack_b = create_stack(0, size_array, arg_index, argv);
	struc = create_struc(stack_a, stack_b, argv, size_array);
	stack_a->struc = struc;
	stack_b->struc = struc;
	start_algo(struc->strategy, stack_a, stack_b, struc->disorder);
	if (struc->benchie)
		generate_benchmark(struc->strategy, struc->disorder, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int	i;
	int	arg_index;

	arg_index = 1;
	while (argv[arg_index][0] == '-')
		arg_index++;
	push_swap(argc - arg_index, argv, arg_index);
}
