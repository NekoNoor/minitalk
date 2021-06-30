/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/21 16:20:00 by nschat        #+#    #+#                 */
/*   Updated: 2021/06/30 17:20:41 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H
# include <stddef.h>

int		ft_isnum(int c);
void	ft_putchar(int c);
void	ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);

#endif
