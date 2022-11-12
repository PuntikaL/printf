/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:31:27 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/13 00:27:27 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);

}
int	hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printhex_up(unsigned int dec)
{	
	if (dec > 15)
	{
		ft_printhex_up(dec / 16);
		write (1,&"0123456789ABCDEF"[dec % 16],1); 
	}
	else
	{
		write (1, &"0123456789ABCDEF"[dec], 1);
	}
	return hexlen(dec); 
}

int	ft_printhex_low(unsigned int dec)
{
	if (dec > 15)
	{
		ft_printhex_low(dec / 16);
		write (1,&"0123456789abcdef"[dec % 16],1); 
	}
	else
	{
		write (1, &"0123456789abcdef"[dec], 1);
	}
	return hexlen(dec); 
}

int	intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len ++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_printstr("-2147483648");
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
	return (intlen(n));
}

char	numlen(unsigned int num)
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
	int	len;

	len = numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	while (n != 0)
	{
		num [len - 1] = n % 10 + '0';
		n = n / 10;
		len --;
	}
	return (num);
}

int	print_unsigned_int(unsigned int n)
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

int ft_printpointer(unsigned long long p)
{
	int	length;

	length = 2;
	ft_printstr("0x");
	length += ft_printhex_low(p);
	return (length);
}
