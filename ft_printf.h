/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpakhlya <mpakhlya@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:15:34 by mpakhlya          #+#    #+#             */
/*   Updated: 2024/03/01 17:20:04 by mpakhlya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printptr(unsigned long long ptr);
int		ft_printnbr(int n);
int		ft_printunsigned(unsigned int n);
int		ft_printhex(unsigned int num, const char format);
int		ft_printpercent(void);
void	ft_putstr(char *str);
void	ft_putptr(unsigned long long num);
int		ft_ptrlen(unsigned long long num);
char	*ft_uitoa(unsigned int num);
void	ft_puthex(unsigned int num, const char format);
int		ft_numlen(unsigned int num);
int		ft_hexlen(unsigned int num);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
#endif
