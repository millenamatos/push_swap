/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:26:34 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/11 17:59:42 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(int fd, char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	else if (specifier == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	else if (specifier == 'p')
		return (ft_putptr_fd(va_arg(args, void *), fd));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	else if (specifier == 'u')
		return (ft_putunbr_fd(va_arg(args, unsigned int), fd));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), specifier, fd));
	else if (specifier == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

static int	ft_parse_type(int fd, const char **format, va_list args)
{
	char	specifier;

	(*format)++;
	if (!(**format))
		return (0);
	specifier = **format;
	(*format)++;
	return (ft_dispatch(fd, specifier, args));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += ft_parse_type(fd, &format, args);
		else
		{
			count += ft_putchar_fd(*format, fd);
			format++;
		}
	}
	va_end(args);
	return (count);
}
