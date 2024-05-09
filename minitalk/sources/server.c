/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:33:27 by skassimi          #+#    #+#             */
/*   Updated: 2024/04/25 11:23:01 by skassimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include"../include/libft.h"
#include <signal.h>
#include <unistd.h>

void	action(int sig, siginfo_t *info, void *context);

int	main(void)
{
	struct sigaction	sa;

	ft_printf("\n\t\t SERVER MINITALK \n\n");
	ft_printf("SERVER PID = %d\n", getpid());
	ft_printf("text zone");
	ft_printf("____________________________________________________\n\n");
	sa.sa_sigaction = action;
	sa.sa_flags = SA_SIGINFO;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1)
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	usleep(100);
	while (1)
		sleep(1);
	return (0);
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int					i = 0;
	static pid_t				client_pid = 0;
	static unsigned char		c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}
