/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:59:06 by aprosper          #+#    #+#             */
/*   Updated: 2022/02/24 14:34:30 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUF_SIZE 5

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*temp;
	int			i;
	
	temp = malloc(sizeof(char));
	while (read(fd, buffer, 1) > 0)
	{
		temp = ft_strjoin(temp, buffer);
		i = 0;
		while (temp[i] != '\n')
		{
			i++;
		}
		printf("%s", temp);
		return (temp);

		
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	get_next_line(fd);
//	str = get_next_line(fd);
//	printf("%s", str);

	if (close(fd) == 1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}

/*
int	main(void)
{
	char	*str = "abcdefghijklmnopiqrstuvwxyz";
	int		i = 'i';
	char	*res;
	
	res = ft_strchr(str, i);

	printf("res = %s\n", res);

	
	return (0);
}
*/
