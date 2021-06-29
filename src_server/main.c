/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:37:17 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/29 15:56:56 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "helpers.h"

int		g_i;

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("0");
	if (signum == SIGUSR2)
		ft_putstr("1");
	g_i++;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	g_i = 0;
	while (1)
	{
		if (g_i == 8)
		{
			ft_putchar('\n');
			g_i = 0;
		}
	}
	return (0);
}
