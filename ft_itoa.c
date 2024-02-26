/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpakhlya <mpakhlya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:58:20 by mpakhlya          #+#    #+#             */
/*   Updated: 2024/02/26 20:17:43 by mpakhlya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	len(int n)
{
	long	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*z(char *result)
{
	if (result == 0)
	{
		result[0] = 0;
		result[1] = '\0';
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;
	int		mp;

	i = len(n);
	if (n < 0)
		mp = -1;
	i = i + (n <= 0);
	result = (char *) malloc(sizeof(char) * (i + 1));
	if (!result)
		return (z(result));
	while (n != 0)
	{
		result[--i] = (char)(n % 10)*(mp + '0');
		n /= 10;
	}
	--i;
	if (mp < 0)
		result[i] = '-';
	return (result);
}
