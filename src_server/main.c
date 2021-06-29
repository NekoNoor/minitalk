/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:37:17 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/29 17:27:09 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "helpers.h"

int				g_i;
unsigned char	g_c;

void	sighandler(int signum)
{
	if (signum == SIGUSR2)
		g_c |= 1;
	if (g_i == 7)
		ft_putchar(g_c);
	g_c <<= 1;
	g_i++;
	if (g_i == 8)
		g_i = 0;
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	g_i = 0;
	signal(SIGUSR1, sighandler);
	signal(SIGUSR2, sighandler);
	while (1)
	{
	}
	return (0);
}
