/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:02:09 by esjalabe          #+#    #+#             */
/*   Updated: 2026/06/10 23:04:28 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_printc(char ap, int *ct)
{
	*ct += write(2, &ap, 1);
}

void	ft_prints(char *ap, int *ct)
{
	int	i;

	i = 0;
	if (ap == 0)
	{
		*ct += write(2, "(null)", 6);
		return ;
	}
	while (ap[i])
	{
		*ct += write(2, &ap[i], 1);
		i += 1;
	}
}

void	ft_printp(void *ap, int *ct)
{
	unsigned long long	exp;
	uintptr_t			y;
	char				*tab_hex;

	tab_hex = "0123456789abcdef";
	exp = 1;
	y = (uintptr_t)ap;
	if (ap == 0)
	{
		*ct += write(2, "(nil)", 5);
		return ;
	}
	*ct += write(2, "0x", 2);
	while (y >= 16)
	{
		y = y / 16;
		exp = exp * 16;
	}
	while (exp >= 1)
	{
		y = (((uintptr_t)ap) / exp) % 16;
		*ct += write (2, &tab_hex[y], 1);
		exp = exp / 16;
	}
}

void	ft_printdi(long nb, int *ct)
{
	unsigned long	exp;
	unsigned long	y;

	exp = 1;
	y = nb;
	if (nb < 0)
	{
		*ct += write (2, "-", 1);
		y = -nb;
		nb = -nb;
	}
	while (y >= 10)
	{
		y = y / 10;
		exp = exp * 10;
	}
	while (exp >= 1)
	{
		y = (nb / exp) % 10;
		y = y + '0';
		*ct += write (2, &y, 1);
		exp = exp / 10;
	}
}

void	ft_printu(unsigned int ap, int *ct)
{
	unsigned int	exp;
	unsigned int	y;

	exp = 1;
	y = ap;
	while (y >= 10)
	{
		y = y / 10;
		exp = exp * 10;
	}
	while (exp >= 1)
	{
		y = ap / exp % 10;
		y = y + '0';
		*ct += write (2, &y, 1);
		exp = exp / 10;
	}
}
