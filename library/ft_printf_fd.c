/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfantoni <gfantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:05:08 by gfantoni          #+#    #+#             */
/*   Updated: 2024/06/25 21:31:05 by gfantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putchar_fd_printf(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

static int	ft_putstr_fd_printf(int fd, char *s)
{
	int	count;

	count = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}

static int	ft_putnbr_fd_printf(int fd, int nbr)
{
	char	*str;
	int		count;

	str = "0123456789";
	count = 0;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		count++;
		nbr *= -1;
	}
	if (nbr / 10 > 0)
		count += ft_putnbr_fd_printf(fd, nbr / 10);
	count += ft_putchar_fd_printf(fd, str[nbr % 10]);
	return (count);
}

static int	ft_parse_format(int fd, const char *format, int *i, va_list args)
{
	int	count;

	count = 0;
	(*i)++;
	if (format[*i] == 'c')
		count += ft_putchar_fd_printf(fd, va_arg(args, int));
	else if (format[*i] == 's')
		count += ft_putstr_fd_printf(fd, va_arg(args, char *));
	else if (format[*i] == 'd' || format[*i] == 'i')
		count += ft_putnbr_fd_printf(fd, va_arg(args, int));
	else
		count += ft_putstr_fd_printf(fd, "Invalid format");
	return (count);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar_fd_printf(fd, format[i]);
		else
			count += ft_parse_format(fd, format, &i, args);
		i++;
	}
	va_end(args);
	return (count);
}
