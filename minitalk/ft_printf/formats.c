/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:42:42 by skassimi          #+#    #+#             */
/*   Updated: 2023/12/23 19:32:32 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_str(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	print_ptr(unsigned long long p)
{
	size_t	len;

	len = 0;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		len += 5;
	}
	else
	{
		write(1, "0x", 2);
		len += 2;
		ft_print_hex(p, "0123456789abcdef");
		len += ft_hexlen(p);
	}
	return (len);
}

size_t	print_int(int nb)
{
	size_t	i;

	i = 0;
	ft_putnbr(nb);
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

size_t	print_unsigned(unsigned int nb)
{
	size_t	i;

	i = 0;
	ft_putnbru(nb);
	if (nb == 0)
		i++;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

size_t	print_hex(long long unsigned int nb, char c)
{
	if (c == 'x')
		ft_print_hex(nb, "0123456789abcdef");
	else
		ft_print_hex(nb, "0123456789ABCDEF");
	return (ft_hexlen(nb));
}
