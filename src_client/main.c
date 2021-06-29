/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:36:20 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/29 15:54:31 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
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

void	send_string(char *str, pid_t pid)
{
	unsigned char	chr;
	int				i;

	while (*str != '\0')
	{
		chr = 0b10000000;
		i = 0;
		while (i < 8)
		{
			if (*str & chr)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			chr >>= 1;
			i++;
			usleep(5);
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	send_string(av[2], ft_atoi(av[1]));
	return (0);
}
