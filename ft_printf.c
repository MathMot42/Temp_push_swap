/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maminet <maminet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:49:54 by esjalabe          #+#    #+#             */
/*   Updated: 2026/06/10 23:08:56 by maminet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_kelforma(char forma, va_list ap, int *ct)
{
	if (forma == 'c')
		ft_printc(va_arg(ap, int), ct);
	if (forma == 's')
		ft_prints(va_arg(ap, char *), ct);
	if (forma == 'p')
		ft_printp(va_arg(ap, void *), ct);
	if (forma == 'd')
		ft_printdi((long)va_arg(ap, int), ct);
	if (forma == 'i')
		ft_printdi((long)va_arg(ap, int), ct);
	if (forma == 'u')
		ft_printu(va_arg(ap, unsigned int), ct);
	if (forma == 'x')
		ft_printx(va_arg(ap, unsigned int), ct);
	if (forma == 'X')
		ft_print_majx(va_arg(ap, unsigned int), ct);
	if (forma == '%')
		ft_printpc(ct);
	if (forma == 'f')
		ft_printfloat(va_arg(ap, double), ct);
	return (0);
}

int	ft_printf(const char *cible, ...)
{
	va_list	ap;
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	va_start(ap, cible);
	while (cible[i])
	{
		if (cible[i] == '%')
		{
			ft_kelforma(cible[i + 1], ap, &ct);
			i += 1;
		}
		else
			ct += write(2, &cible[i], 1);
		i += 1;
	}
	va_end(ap);
	return (ct);
}

/*int	main()
{
	char			a[] = "orange";
	char			b = 'c';
	unsigned int	d = 222;
	int				e = -23547;
	int				ct;
	int				ct2;

	ft_printf("\nprintf\n\n");
	ct = printf(
			"character : %c\n"
			"string : %s\n"
			"adresse pointeur : %p\n"
			"decimal : %d\n"
			"integer : %i\n"
			"unsigned decimal : %u\n"
			"hexadecimal lower : %x\n"
			"hexadecimal upper : %X\n"
			"pourcentage : %%\n", b, a, a, e, e, d, d, d);
	
	ft_printf("\nft_printf\n\n");
	ct2 = ft_printf(
			"character : %c\n"
			"string : %s\n"
			"adresse pointeur : %p\n"
			"decimal : %d\n"
			"integer : %i\n"
			"unsigned decimal : %u\n"
			"hexadecimal lower : %x\n"
			"hexadecimal upper : %X\n"
			"pourcentage : %%\n", b, a, a, e, e, d, d, d);
	printf("\ncompteur printf: %d\n", ct);
	printf("compteur ft_printf: %d\n", ct2);
}*/
