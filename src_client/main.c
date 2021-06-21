/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:36:20 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/21 16:33:35 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "helpers.h"

static int	ft_atoi(char *s)
{
	int	sign;
	int	n;

	n = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isnum(*s))
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n * sign);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	ft_putstr(av[2]);
	return (0);
}
