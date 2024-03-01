/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpakhlya <mpakhlya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:55:01 by mpakhlya          #+#    #+#             */
/*   Updated: 2024/03/01 17:19:32 by mpakhlya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_printchar(va_arg(args, int));
	else if (format == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		i += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		i += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		i += ft_printpercent();
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		plen;

	i = 0;
	plen = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			plen += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			plen += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (plen);
}
