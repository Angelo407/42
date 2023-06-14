/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:36:36 by aprosper          #+#    #+#             */
/*   Updated: 2022/02/24 13:42:08 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char    *get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strchr(const char *str, int c);