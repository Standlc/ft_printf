
#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_itohexa(unsigned long n, int is_lower_case);
int		ft_strlen(char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char    *tohexa_memory(unsigned long n);

#endif