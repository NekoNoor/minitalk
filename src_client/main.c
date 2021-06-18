/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/17 17:36:20 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/18 10:45:01 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi(char *s)
{
	int sign;
	int n;

	n = 0;
	if (*s == '+' || *s == '-')
	{
		if (*s == '+')
			sign = 1;
		else
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

int main(int ac, char **av)
{
	int pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	ft_putstr(av[2]);
	return (0);
}
