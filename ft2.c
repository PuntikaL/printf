/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:31:27 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/13 07:27:12 by pleepago         ###   ########.fr       */
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
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
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

int	ft_printhex_up(unsigned int n)
{	
	unsigned long dec;

	if (n == 0)
		return ft_putchar('0');
	dec = (unsigned long)n;
	if (dec > 15)
	{
		ft_printhex_up(dec / 16);
		write (1,&"0123456789ABCDEF"[dec % 16],1); 
	}
	else
		write (1, &"0123456789ABCDEF"[dec], 1);
	return hexlen(dec); 
}

int	ft_printhex_low(unsigned int n)
{
	unsigned long dec;
	
	if (n == 0)
		return ft_putchar('0');
	dec = (unsigned long)n;
	if (dec > 15)
	{
		ft_printhex_low(dec / 16);
		write (1,&"0123456789abcdef"[dec % 16],1); 
	}
	else
		write (1, &"0123456789abcdef"[dec], 1);
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

int	ptrlen(uintptr_t num)
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

int	ft_printptr(uintptr_t n)
{	
	unsigned long dec;

	if (n == 0)
		return ft_putchar('0');
	dec = (unsigned long)n;
	if (dec > 15)
	{
		ft_printptr(dec / 16);
		write (1,&"0123456789abcdef"[dec % 16],1); 
	}
	else
		write (1, &"0123456789abcdef"[dec], 1);
	return hexlen(dec); 
}


int ft_printpointer(unsigned long long p)
{
	int	length;

	length = 2;
	ft_printstr("0x");
	if(p == 0)
		length += write(1, "0", 1);
	else
	{
		ft_printptr(p);
		length += ptrlen(p);
	}
	return (length);
}
