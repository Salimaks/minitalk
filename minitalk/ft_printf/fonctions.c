/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:56:27 by skassimi          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:29 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_print_hex(long long unsigned int nb, char *base)
{
	if (nb >= 16)
		ft_print_hex(nb / 16, base);
	ft_putchar(base[nb % 16]);
}

size_t	ft_hexlen(long long unsigned int nb)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	long long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void	ft_putnbru(unsigned int n)
{
	long unsigned int	nb;

	nb = n;
	if (nb >= 10)
		ft_putnbru(nb / 10);
	ft_putchar((nb % 10) + '0');
}
