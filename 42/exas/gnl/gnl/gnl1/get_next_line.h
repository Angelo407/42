/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:36:36 by aprosper          #+#    #+#             */
/*   Updated: 2022/02/05 16:05:44 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char    *get_next_line(int fd);
//int     get_next_line(int fd);
void	ft_putchar(char c);
void	ft_putchar_fd(int fd, char c);
void	ft_putstr(const char *str);
void	ft_putstr_fd(int fd, char *str);
void	ft_putnbr(int nb);
void	ft_putnbr_fd(int nb, int fd);
size_t	ft_strlen(const char *str);
