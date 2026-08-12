/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:12:53 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/08/11 17:46:48 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex_fd(unsigned long long address, int fd)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (address >= 16)
		count += ft_putptr_hex_fd(address / 16, fd);
	count += ft_putchar_fd(base[address % 16], fd);
	return (count);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(fd, "(nil)", 5));
	count += write (fd, "0x", 2);
	count += ft_putptr_hex_fd((unsigned long long)ptr, fd);
	return (count);
}

int	ft_puthex_fd(unsigned int nbr, char specifier, int fd)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (specifier == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_puthex_fd(nbr / 16, specifier, fd);
	count += ft_putchar_fd(base[nbr % 16], fd);
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
		count += ft_putnbr_fd(nbr / 10, fd);
	count += ft_putchar_fd((nbr % 10) + '0', fd);
	return (count);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned int	div;
	unsigned int	temp;
	char			digit;
	int				count;

	count = 0;
	div = 1;
	temp = n;
	while (temp >= 10)
	{
		div *= 10;
		temp /= 10;
	}
	while (div > 0)
	{
		digit = (n / div) + '0';
		count += ft_putchar_fd(digit, fd);
		n = n % div;
		div /= 10;
	}
	return (count);
}
