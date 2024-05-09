/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:50:11 by skassimi          #+#    #+#             */
/*   Updated: 2024/04/25 13:55:55 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include"../libft/libft.h"
#include "../include/ft_printf.h"

static void	handler(int sig)
{
	static int	i;

	i = 0;
	if (sig == SIGUSR1)
	{
		++i;
	}
	else
	{
		ft_putnbr_fd(i, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	ft_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(400);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	ft_printf("\n\t\tThe message has been sent succesfuly\n\n");
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_kill(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
