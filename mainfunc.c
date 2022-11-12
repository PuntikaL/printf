/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:33:48 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/12 21:35:57 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int get_format(va_list args, const char format)
{
	int len;
  
	len = 0;
	if (format == 'c')
		len += ft_putchar(va_args(args, int));
	else if (format == 's')
		len += ft_printstr(va_args(args, char *));
	else if (format == 'p')
		len += ft_printpointer(va_args(args, unsigned long long));
	else if (format == 'd')
		len += ft_putnbr(va_args(args, int));
	else if (format == 'u')
		len += ft_printunbr(va_args(args, unsigned int), 0); 
	else if (format == 'x')
		len += ft_printhexLow(va_args(args, unsigned int), 0);
	else if (format == 'X')
		len += ft_printhexUp(va_args(args, unsigned int));
	else if (format == 'i')
		len += ft_putnbr(va_args(args, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int ft_printf(const char *, ...)
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
	  print_length += ft_printchar(str[i])
	 i++;
  }
  va_end(args);
  return (print_length);
 }
