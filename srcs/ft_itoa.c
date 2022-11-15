/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:55:41 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 11:55:42 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static int	len(long n)
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

	ascii = malloc((len(n) + 1) * sizeof(char));
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
