/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:37:17 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/30 17:20:41 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "helpers.h"

int				g_i;
unsigned char	g_c;

void	sighandler(int sig, siginfo_t *info, void *context)
{
	pid_t	pid;

	(void)context;
	pid = info->si_pid;
	if (sig == SIGUSR2)
		g_c |= 1;
	if (g_i == 7)
	{
		if (g_c != '\0')
			ft_putchar(g_c);
		else
		{
			usleep(50);
			kill(pid, SIGUSR1);
		}
	}
	g_c <<= 1;
	g_i++;
	if (g_i == 8)
		g_i = 0;
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr(pid);
	ft_putchar('\n');
	g_i = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighandler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
