/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleepago <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:33:48 by pleepago          #+#    #+#             */
/*   Updated: 2022/11/11 21:51:41 by pleepago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int get_format(va_list args, const char format)
{
	int len;
  
	len = 0;
	if (format == 'c')
		len += ft_printchar(va_args(args, int));
	else if (format == 's')
		len += ft_printchar(va_args(args, char *));
	else if (format == 'p')
		len += ft_printchar(va_args(args, unsigned long long));
	else if (format == 'd')
		len += ft_printchar(va_args(args, int));
	else if (format == 'u')
		len += ft_printchar(va_args(args, unsigned int)); 
	else if (format == 'x')
		len += ft_printchar(va_args(args, unsigned int));
	else if (format == '%')
		len += ft_printchar(va_args(args, char *));
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
