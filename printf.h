#ifndef LIBFT_H
# define LIBFT_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *, ...);
int get_format(va_list args, const char format);
int ft_putchar(int a);
int ft_printstr(char *str);
int	ft_printhexUp(unsigned int dec, int length);
int	ft_printhexLow(unsigned int dec, int length);
void	ft_putnbr(int n, int length);
char	numlen(unsigned int n);
char	*ft_utoa(unsigned int n);
void	print_unsigned_int(unsigned int n);
int ft_printpointer(unsigned long long);

#endif