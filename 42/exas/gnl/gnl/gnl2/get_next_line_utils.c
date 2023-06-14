/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:37:46 by aprosper          #+#    #+#             */
/*   Updated: 2022/02/24 13:42:14 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*str3;
	int		i;
	int		j;
	size_t	len;	

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	str3 = (char *)malloc(sizeof(char) * len);
	if (!str3)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		str3[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] != '\0')
		str3[i++] = str2[j++];
	str3[i] = '\0';
	return (str3);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
