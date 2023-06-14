/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:55 by creyt             #+#    #+#             */
/*   Updated: 2022/01/25 15:27:06 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

char ft_putstr(char *str)
{
	int i;
	
	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnb(long int nb)
{
	int count;
	
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		count += ft_putnb(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_puthexa(unsigned long nb)
{
	int count;
	char *table;

	count = 0;
	table = "0123456789abcdef";
	if (nb > 15)
		count += ft_puthexa(nb / 16);
	count += ft_putchar(table[nb % 16]);
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int	count;

	va_start(ap, str);
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != '%')
			write(1, str, 1);
		else
		{
			str++;
			if (*str == '%')
				count += write(1, "%", 1);
			if (*str == 's')
				count += ft_putstr(va_arg(ap, char *));
			if (*str == 'd')
				count += ft_putnb(va_arg(ap, int));
			if (*str == 'x')
				count += ft_puthexa(va_arg(ap, unsigned int));
		}
		str++;
	}
	va_end(ap);
	return (count);
}

int	main (void)
{
	char *str = "-1234";
	int	nb = -1234;
	int	nb2 = 4;
	int	hexa = -1234;
	int retour_printf = 0;
	int	retour_ft_printf = 0;

	retour_printf = printf("s: %s || d: %d || d: %d || x: %x\n", str, nb, nb2, hexa);
	retour_ft_printf = ft_printf("s: %s || d: %d || d: %d || x: %x\n", str, nb, nb2, hexa);
}
