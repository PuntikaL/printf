/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:31:27 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/12 21:49:27 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(int a)
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

int	ft_printhexUp(unsigned int dec, int length)
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

int	ft_printhexLow(unsigned int dec, int length)
{
	if (dec > 15)
	{
		ft_printhex(dec / 16, length);
		length += ft_putchar(dec % 16 + '0');
	}
	else if (dec > 9)
	{
		if (dec == 10)
			length += ft_putchar('a');
		if (dec == 11)
			length += ft_putchar('b');
		if (dec == 12)
			length += ft_putchar('c');
		if (dec == 13)
			length += ft_putchar('d');
		if (dec == 14)
			length += ft_putchar('e');
		if (dec == 15)
			length += ft_putchar('f');
	}
	else
		length += ft_putchar(dec);
	return length; 
}

int	ft_putnbr(int n, int length)
{
	if (n == -2147483648)
		length += ft_putstr("-2147483648");
	else if (n < 0)
	{
		length += ft_putchar('-');
		ft_putnbr(-n, length);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		length += ft_putchar(n % 10 + '0');
	}
	else
		length += ft_putchar(n + '0');
	return (length);
}

char	numlen(unsigned int n)
{
	int	len;
	
	len	= 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int	length;

	length = numlen(n);
	num = (char *)malloc(sizeof(char) * (length + 1));
	if (!num)
		return (0);
	while (n != 0)
	{
		num [len - 1] = n % 10 + '0';
		n = n / 10;
		len --;
	}
}

void	print_unsigned_int(unsigned int n)
{
	int	length;
	char	*num;
	
	length = 0;
	if (n == 0)
		length += ft_putchar('0');
	else
	{
		num = ft_utoa(n);
		length += ft_printstr(num);
		free(num);
	}
	return (length);
}

int ft_printpointer(unsigned long long)
{
	int	length;

	length = 2;
	ft_putstr("0x");
	length += ft_printhex();
	return (length);
}