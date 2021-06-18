/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:37:17 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/18 10:32:41 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <signal.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putnbr(n / 10);
		n = -(n % 10);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

size_t ft_strlen(char *s)
{
	size_t len;

	len = 0;
	while (*s != '\0')
		len++;
	return (len);
}

void ft_putstr(char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
}

void sighandler(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("sigusr1\n");
	if (signum == SIGUSR2)
		ft_putstr("sigusr2\n");
}

int main(void)
{
	pid_t pid;

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
