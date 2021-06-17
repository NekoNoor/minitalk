/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:37:17 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/17 17:53:25 by nschat        ########   odam.nl         */
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

int main(void)
{
	pid_t pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');

	return (0);
}
