/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:47:49 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 10:47:50 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

int	handle_malloc_error(void)
{
	return (-1);
}

unsigned int	absolute(int n)
{
	if (n < 0)
		return ((unsigned int)-n);
	return ((unsigned int)n);
}

static int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (0);
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
