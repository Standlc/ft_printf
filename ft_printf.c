/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:23:09 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/14 13:27:22 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	indexof(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*formats()
{
	return ("cspdiuxX%%");
}

int	print(char format, va_list pargs)
{
	if (format == 'c')
		return (ft_putchar(va_arg(pargs, int)));
	if (format == 's')
		return (ft_putstr(va_arg(pargs, char *)));
	if (format == 'i')
		return (ft_putstr(ft_itoa(va_arg(pargs, int))));
	if (format == 'd')
		return (ft_putstr(ft_itoa(va_arg(pargs, double))));
	if (format == 'u')
		return (ft_putstr(ft_unsigned_itoa(va_arg(pargs, unsigned int))));
	if (format == 'x')
		return (ft_putstr(ft_itohexa(va_arg(pargs, int), 1)));
	if (format == 'X')
		return (ft_putstr(ft_itohexa(va_arg(pargs, int), 0)));
	if (format == '%')
		return (ft_putchar('%'));
	if (format == 'p')
		return (ft_putstr(tohexa_memory(va_arg(pargs, long))) + 2);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int	length;
	va_list pargs;
	va_start(pargs, str);

	length = 0;
	while (*(++str))
	{
		if (*(str - 1) == '%' && indexof(formats(), *str) != -1)
			length += print(*str, pargs);
		else if (*str != '%')
		{
			write(1, str, 1);
			length++;
		}
	}
	va_end(pargs);
	return (length);
}

int main()
{
	char	str[] = "Hello world";
	char	*p = str;

	// printf("\n%d\n", ft_printf("%c %s %i %u %% %i %d %x %X %% %p", str[0], str, 504, 400000000, 16, 42.5, 123, 123, p));
	// printf("\n%d\n",    printf("%c %s %i %u %% %i %d %x %X %% %p", str[0], str, 504, 400000000, 16, 42, 123, 123, p));
	ft_printf(" %c ", '0');
}
