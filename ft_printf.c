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

#include "include/ft_printf.h"
#include "include/utils.h"
#include "include/format_handlers.h"

static int	indexof(char *str, char c)
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

static void	initialize_function_arr(int (*arr[9])(va_list, char *, int))
{
	arr[0] = &handle_c;
	arr[1] = &handle_s;
	arr[2] = &handle_p;
	arr[3] = &handle_d;
	arr[4] = &handle_i;
	arr[5] = &handle_u;
	arr[6] = &handle_x;
	arr[7] = &handle_upperx;
	arr[8] = &handle_percent;
}

static int	handle_format(char format, va_list pargs)
{
	int		(*print_functions[9])(va_list, char *, int);
	char	*p;
	int		length;

	initialize_function_arr(print_functions);
	p = NULL;
	length = 0;
	return (print_functions[indexof("cspdiuxX%%", format)](pargs, p, length));
}

int	ft_printf(const char *str, ...)
{
	int		format_printed_len;
	int		total_printed_length;
	va_list	pargs;

	va_start(pargs, str);
	total_printed_length = 0;
	while (*str)
	{
		if (*str == '%' && indexof("cspdiuxX%%", *(str + 1)) != -1)
		{
			format_printed_len = handle_format(*(str + 1), pargs);
			str++;
			if (format_printed_len == -1 || !*str)
				break ;
			total_printed_length += format_printed_len;
		}
		else if (*str != '%')
		{
			write(1, str, 1);
			total_printed_length++;
		}
		str++;
	}
	va_end(pargs);
	return (total_printed_length);
}

// #include <limits.h>
// int main()
// {
// 	char	str[] = "Hello world";
// 	char	*p = str;

// 	printf("\n%d\n", ft_printf(",%c %s %i %u %% 
// 		%i %d %x %X %% %p .%s. %s %%%% %p %p %d %s\t %c %x %u %d %d",
// 		str[0], str, 504, -400000000, 16, 42, -6,
// 		2123, p, "", " - ", NULL, -2, 0, NULL, 150, INT_MIN, INT_MIN, 
// 		INT_MIN, LONG_MAX));

// 	// printf("\n%d\n",    printf(",%c %s %i %u %% 
// 	// 	%i %d %x %X %% %p .%s. %s %%%% %p %p %d %s\t %c %x %u %d %d",
// 	// 	str[0], str, 504, -400000000, 16, 42, -6,
// 	// 	2123, p, "", " - ", NULL, -2, 0, NULL, 150, INT_MIN, INT_MIN, 
// 	// 	INT_MIN, LONG_MAX));

// 	return (0);
// }
