#include "ft_printf.h"

int	len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

unsigned int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char			*ascii;
	int				i;
	unsigned int	unsigned_n;

	unsigned_n = absolute(n);
	ascii = malloc(len(n) + 1);
	if (!ascii)
		return (0);
	i = len(n) - 1;
	ascii[i + 1] = 0;
	ascii[0] = '0';
	if (n < 0)
		ascii[0] = '-';
	while (unsigned_n)
	{
		ascii[i] = unsigned_n % 10 + '0';
		unsigned_n /= 10;
		i--;
	}
	return (ascii);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*ascii;
	int				i;

	ascii = malloc(len(n) + 1);
	if (!ascii)
		return (0);
	i = len(n) - 1;
	ascii[i + 1] = 0;
	ascii[0] = '0';
	while (n)
	{
		ascii[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (ascii);
}

char	*hexa_base_low()
{
    return ("0123456789abcdef");
}

char	*hexa_base_upp()
{
    return ("0123456789ABCDEF");
}

int	hexa_len(long n)
{
    int	i;

    i = 0;
    if (n < 0)
        i++;
    while (n)
    {
        n /= 16;
        i++;
    }
    return (i);
}

char	*ft_itohexa(unsigned long n, int is_lower_case)
{
    char    *hexa;
    int     i;

    hexa = malloc((hexa_len(n) + 1) * sizeof(char));    
    if (!hexa)
        return (0);
    i = hexa_len(n) - 1;
    hexa[i + 1] = 0;
    hexa[0] = '0';
    while (n)
    {
        if (is_lower_case)
            hexa[i] = hexa_base_low()[absolute(n % 16)];
        else
            hexa[i] = hexa_base_upp()[absolute(n % 16)];
        n /= 16;
        i--;
    }
    return (hexa);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, s + i, 1);
		i++;
	}
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
    return (1);
}

char    *tohexa_memory(unsigned long n)
{
    ft_putstr("0x");
    return (ft_itohexa(n, 1));
}