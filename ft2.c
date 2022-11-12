/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:31:27 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/12 07:58:12 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_printchar(int a)
{
	write (1, &a, 1);
	return (1);
}

int ft_printstr(char *str)
{
	int len;
	int i;
	
	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_printchar(str[i]);
		i++;
	}
}

int	ft_printhex(unsigned int dec, int length)
{
	if (dec > 15)
	{
		ft_printhex(dec / 16, length);
		length += ft_putchar(dec % 16 + '0');
	}
	else if (dec > 9)
	{
		if (dec == 10)
			length += ft_putchar('A');
		if (dec == 11)
			length += ft_putchar('B');
		if (dec == 12)
			length += ft_putchar('C');
		if (dec == 13)
			length += ft_putchar('D');
		if (dec == 14)
			length += ft_putchar('E');
		if (dec == 15)
			length += ft_putchar('F');
	}
	else
		length += ft_putchar(dec);
	return length; 
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int ft_printpointer(unsigned long long)
{
	
}
