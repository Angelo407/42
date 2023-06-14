/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:37:09 by aprosper          #+#    #+#             */
/*   Updated: 2022/01/31 17:47:08 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

#define BUF_SIZE 150

int	explanation_one(void)
{
	int	fd;
	int ret;

	char buf[BUF_SIZE];
	
	// O_APPEND : permet d ecrire depuis le dernier octet du fichier 
	//fd = open("42", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
//	printf("%d\n", fd);
//	ft_putchar_fd(fd, 'Z');
//	ft_putstr_fd(fd, "Hello World !");
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	printf("%s\n", buf);
//	printf("%d\n", ret);
	if (close(fd) == 1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}


int	explanation_two(void)
{
	int	fd;
	int ret;

	char buf[BUF_SIZE + 1];
	
	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(buf);
	}
	ft_putnbr(ret);
	if (close(fd) == 1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}

//-------------------------------------------------------------------------



/*char	*get_next_line(int fd)
{
	ssize_t	ret;
	char buf[BUF_SIZE];
	static char stock[100000];
	while (ret > 0)
	{
		line = find_next_line_in_stock();
		if (line)
			return(line)
		ret = read_next_buffer();
		
	}
	ret = read(fd, buf, BUF_SIZE); // return la valeur de BUF_SIZE => 15

	while (buf[BUF_SIZE] != '\n')
	{
		buf[BUF_SIZE] = buf[BUF_SIZE] + 1;

	}

	printf("return : %c\n", buf[BUF_SIZE]);
	return &(buf[BUF_SIZE]);
}*/




char	*get_next_line(int fd)
{
	ssize_t	ret;
	char buf[BUF_SIZE];
	static char stock[10000];
	
	ret = read(fd, buf, BUF_SIZE); 
//	printf("ret = %zd\n", ret);
	
	if (buf[BUF_SIZE] != '\n')
	{
		ft_putstr_fd(fd, buf);
	}
	

	return (buf[BUF_SIZE]);
}


int main(void)
{
//	explanation_one();
//	explanation_two();
	

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
