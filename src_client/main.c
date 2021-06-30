/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:36:20 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/30 17:16:52 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
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

void	send_byte(char str_c, pid_t pid)
{
	unsigned char	chr;
	int				i;
	int				sig;

	chr = 0b10000000;
	i = 0;
	while (i < 8)
	{
		if (str_c & chr)
			sig = SIGUSR2;
		else
			sig = SIGUSR1;
		if (kill(pid, sig) == -1)
		{
			ft_putstr("Invalid pid\n");
			exit(1);
		}
		chr >>= 1;
		i++;
		usleep(50);
	}
}

void	send_string(char *str, pid_t pid)
{
	while (*str != '\0')
	{
		send_byte(*str, pid);
		str++;
	}
	send_byte(*str, pid);
}

void	success(int signum)
{
	(void)signum;
	ft_putstr("String received by server\n");
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_putstr("Invalid parameters, use ");
		ft_putstr(av[0]);
		ft_putstr(" [pid] [string]\n");
		return (1);
	}
	signal(SIGUSR1, success);
	send_string(av[2], ft_atoi(av[1]));
	while (1)
	{
		pause();
	}
	return (0);
}
