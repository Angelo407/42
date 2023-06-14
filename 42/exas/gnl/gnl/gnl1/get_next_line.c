/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:59:06 by aprosper          #+#    #+#             */
/*   Updated: 2022/02/05 16:20:13 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

#define BUF_SIZE 3

char	*get_next_line(int fd)
{
	int	i;
	char *buffer[BUF_SIZE];
	static char temp[1000];
	
	i = 0;
	while (read(fd, buffer, BUF_SIZE) > 0)
	{	
		temp[i] = buffer[i];
		printf("temp = %s | i = %d\n", temp, i);
		i++;
	}
	return (temp);
}



int main(void)
{

	int	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}

	get_next_line(fd);
	

	if (close(fd) == 1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}

	return (0);
}