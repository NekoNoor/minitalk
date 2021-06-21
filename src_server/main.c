/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:37:17 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/21 16:32:00 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "helpers.h"

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("sigusr1\n");
	if (signum == SIGUSR2)
		ft_putstr("sigusr2\n");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
