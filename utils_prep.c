/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_prep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:54:52 by maminet           #+#    #+#             */
/*   Updated: 2026/06/11 18:07:02 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


float	calculate_disorder(int *stack_a, int size)
{
	int		i;
	int		j;
	float	mistakes;
	float	total_pairs;

	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (stack_a[i] > stack_a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}


int	check_arg(int check_bench, char **argv)
{
	int	(i) = 1;

	while (i < 3)
	{
		if (check_bench)
		{
			if (string_equals(argv[i], "--bench"))
				return (1);
		}
		else
		{
			if (string_equals(argv[i], "--simple"))
				return (1);
			if (string_equals(argv[i], "--medium"))
				return (2);
			if (string_equals(argv[i], "--complex"))
				return (3);
			if (string_equals(argv[i], "--adaptive"))
				return (4);
		}
		i++;
	}
	if (check_bench)
		return (0);
	return (4);
}


void	start_algo(int strategy, stack *stack_a, stack *stack_b, float disorder)
{
    //PRINT(strategy);
	if (strategy == 1)
		simple_algo(stack_a, stack_b);
	if (strategy == 2)
		medium_algo(stack_a, stack_b);
	if (strategy == 3)
		complex_algo(stack_a, stack_b);
	if (strategy == 4)
	{
		if (disorder < 0.2)
			simple_algo(stack_a, stack_b);
		if (disorder >= 0.2 && disorder < 0.5)
			medium_algo(stack_a, stack_b);
		if (disorder >= 0.5)
			complex_algo(stack_a, stack_b);
	}
}

char	*get_strat_name(int strategy, float disorder)
{
	if (strategy == 1)
		return ("Simple / O(n²)");
	if (strategy == 2)
		return ("Medium / O(n√n)");
	if (strategy == 3)
		return ("Complex / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (disorder >= 0.2 && disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}
void	generate_benchmark(int strategy, float disorder, stack *stack_a,
		stack *stack_b)
{
	int	total_ops;

	total_ops = 0;
	//printf("[bench temp] arr : ");
	//print_stack(stack_a);
	//PRINT(disorder);
	ft_printf("[bench] disorder: %f%%\n", disorder * 100);
	ft_printf("[bench] strategy: %s\n", get_strat_name(strategy, disorder));
	total_ops = stack_a->p + stack_a->r + stack_a->rr + stack_a->rrr
		+ stack_a->rrrr + stack_a->s + stack_a->ss + stack_b->p + stack_b->r
		+ stack_b->rr + stack_b->rrr + stack_b->rrrr + stack_b->s + stack_b->ss;
	ft_printf("[bench] total_ops: %d\n", total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", stack_a->s,
		stack_b->s, (stack_a->ss + stack_b->ss), stack_a->p, stack_b->p);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n", stack_a->r,
		stack_b->r, (stack_a->rr + stack_b->rr), stack_a->rrr, stack_b->rrr,
		(stack_a->rrrr + stack_b->rrrr));
	//printf(" is sort ? %d", is_sort(stack_a));
}

// void    print(char *str){
//     int i;
    
//     i = 0;
//     while(str[i]){
//         write(2, &str[i], 1);
//         i++
//     }
// }
