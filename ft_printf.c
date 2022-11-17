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
	int		length;
	va_list	pargs;

	va_start(pargs, str);
	length = 0;
	while (*str)
	{
		if (*str == '%' && indexof("cspdiuxX%%", *(str + 1)) != -1)
		{
			length += handle_format(*(str + 1), pargs);
			str++;
			if (!*str)
				break ;
		}
		else if (*str != '%')
		{
			write(1, str, 1);
			length++;
		}
		str++;
	}
	va_end(pargs);
	return (length);
}

// int main()
// {
// 	char	str[] = "Hello world";
// 	char	*p = str;

// 	printf("\n%d\n", ft_printf(",%c %s %i %u %%
// %i %d %x %X %% %p .%s. %s %%%% %p %p %d %s\t",
// 		str[0], str, 504, -400000000, 16, 42, -6,
// 2123, p, "", " - ", NULL, -2, 0, NULL));
// 	printf("\n%d\n",    printf(",%c %s %i %u %% 
// %i %d %x %X %% %p .%s. %s %%%% %p %p %d %s\t",
// 		str[0], str, 504, -400000000, 16, 42, -6,
// 2123, p, "", " - ", NULL, -2, 0, NULL));
// }
