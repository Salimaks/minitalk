/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:18:48 by skassimi          #+#    #+#             */
/*   Updated: 2023/12/26 13:04:58 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

size_t	formats(char c, va_list av)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(av, int));
	else if (c == 's')
		len += print_str(va_arg(av, char *));
	else if (c == 'p')
		len += print_ptr(va_arg(av, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += print_int(va_arg(av, int));
	else if (c == 'u')
		len += print_unsigned(va_arg(av, unsigned int));
	else if (c == 'x' || c == 'X')
		len += print_hex((long long unsigned int)va_arg(av, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	else
	{
		len += ft_putchar('%');
		len += ft_putchar(c);
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	size_t	len;
	va_list	av;

	i = 0;
	len = 0;
	va_start(av, s);
	if (s == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += formats(s[i + 1], av);
			i++;
		}
		else
			len += ft_putchar(s[i]);
		i++;
	}
	va_end(av);
	return (len);
}
