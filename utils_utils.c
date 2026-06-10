/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:52:37 by maminet           #+#    #+#             */
/*   Updated: 2026/06/10 15:53:27 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *nptr)
{
	int	i;
	int	negatif;
	int	result;

	i = 0;
	negatif = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
	{
		i++;
	}
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			negatif = -negatif;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * negatif);
}

void	print_stack(stack *staack)
{
	int	i;

	i = 0;
	while (i < staack->size)
	{
		printf("%d ", staack->array[i]);
		i++;
	}
	printf("\n");
}
int	is_sort(stack *staack)
{
	int	i;
	int	size;

	i = 0;
	size = staack->size;
	while (i < size - 1)
	{
		if (staack->array[i] > staack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int	string_equals(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (!str2[i] || str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}