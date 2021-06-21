/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:36:20 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/21 16:17:33 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "helpers.h"

int main(int ac, char **av)
{
	int pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	ft_putstr(av[2]);
	return (0);
}
