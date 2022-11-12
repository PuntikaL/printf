#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_printf(const char *, ...);
int get_format(va_list args, const char format);
int ft_putchar(int a);
int ft_printstr(char *str);
int	ft_printhex_up(unsigned int dec);
int	ft_printhex_low(unsigned int dec);
int	ft_putnbr(int n);
char	numlen(unsigned int n);
char	*ft_utoa(unsigned int n);
int	print_unsigned_int(unsigned int n);
int ft_printpointer(unsigned long long);
int	intlen(int n);
int	hexlen(unsigned int num);
#endif
