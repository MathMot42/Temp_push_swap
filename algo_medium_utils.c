/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 23:01:59 by maminet           #+#    #+#             */
/*   Updated: 2026/06/11 23:32:38 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ft_sqrt(double n)
{
	double	x;
	int		i;

	if (n < 1)
		return (-1);
	if (n == 0)
		return (0);
	x = n / 2;
	i = -1;
	while (++i < 50)
		x = (x + n / x) * 0.5;
	return (x);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	itteration_count;
	int	i;
	int	c;

	itteration_count = 0;
	i = 0;
	while (itteration_count < size)
	{
		if (tab[i] > tab[i + 1])
		{
			c = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = c;
		}
		if (i >= size - 2 - itteration_count)
		{
			itteration_count++;
			i = -1;
		}
		i++;
	}
}
