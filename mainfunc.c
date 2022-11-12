/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:33:48 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/12 23:36:07 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_format(va_list args, const char format)
{
	int len;
 
       	write (1, &format, 1);
	if (format != 'X')
		write (3, "no\n", 1);	
	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_printpointer(va_arg(args, unsigned long long));
	else if (format == 'd')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += print_unsigned_int(va_arg(args, unsigned int)); 
	else if (format == 'x')
	{
		len += ft_printhexLow(va_arg(args, unsigned int));
		write (1, &format, 1);
	}
	else if (format == 'X')
		len += ft_printhexUp(va_arg(args, unsigned int));
	else if (format == 'i')
		len += ft_putnbr(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int ft_printf(const char *str, ...)
{
  int i;
  va_list args;
  int print_length;
  
  i = 0;
  print_length = 0;
  va_start(args, str);
  while (str[i])
  {
	if (str[i] == '%')
	{
	  i += 1;
	  print_length += get_format(args, str[i]);
	}
	else
	  print_length += ft_putchar(str[i]);
	 i++;
  }
  va_end(args);
  return (print_length);
 }
