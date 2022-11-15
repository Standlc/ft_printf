/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stde-la- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:57:17 by stde-la-          #+#    #+#             */
/*   Updated: 2022/11/15 11:57:19 by stde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

static char	*hexa_base_low(void)
{
	return ("0123456789abcdef");
}

static char	*hexa_base_upp(void)
{
	return ("0123456789ABCDEF");
}

static int	hexa_len(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
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
	char	*hexa;
	int		i;

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
