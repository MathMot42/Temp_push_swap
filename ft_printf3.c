/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:03:20 by esjalabe          #+#    #+#             */
/*   Updated: 2026/06/10 23:17:29 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printx(unsigned int nb, int *ct)
{
	unsigned int	exp;
	unsigned int	y;
	char			*tab_hex;

	tab_hex = "0123456789abcdef";
	exp = 1;
	y = nb;
	while (y >= 16)
	{
		y = y / 16;
		exp = exp * 16;
	}
	while (exp >= 1)
	{
		y = nb / exp % 16;
		*ct += write(2, &tab_hex[y], 1);
		exp = exp / 16;
	}
}

void	ft_print_majx(unsigned int nb, int *ct)
{
	unsigned int	exp;
	unsigned int	y;
	char			*tab_hex;

	tab_hex = "0123456789ABCDEF";
	exp = 1;
	y = nb;
	while (y >= 16)
	{
		y = y / 16;
		exp = exp * 16;
	}
	while (exp >= 1)
	{
		y = nb / exp % 16;
		*ct += write(2, &tab_hex[y], 1);
		exp = exp / 16;
	}
}

void	ft_printpc(int *ct)
{
	*ct += write(2, "%", 1);
}

void	ft_printfloat(float f, int *ct)
{
	char	c;

	if (f < 10)
	{
		c = ((int)f) + '0';
		write(2, &c, 1);
	}
	else if (f < 100)
	{
		c = ((int)f / 10) + '0';
		write(2, &c, 1);
		c = ((int)f % 10) + '0';
		write(2, &c, 1);
	}
	else
	{
		write(2, "100", 3);
	}
	write(2, ".", 1);
	f = f - (int)f;
	f = f * 100;
	c = ((int)f / 10) + '0';
	write(2, &c, 1);
	c = ((int)f % 10) + '0';
	write(2, &c, 1);
}
