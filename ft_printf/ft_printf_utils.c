/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:24:24 by ebudak            #+#    #+#             */
/*   Updated: 2022/02/25 19:55:09 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	char	u;

	if (n == -2147483648)
		ft_putstr("-2147483648", len);
	else
	{
		if (n < 0)
		{
			*len += write(1, "-", 1);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, len);
		}
		u = ((n % 10) + 48);
		*len += write(1, &u, 1);
	}
}

void	ft_putunbr(unsigned int n, int *len)
{
	if (n > 0)
	{
		ft_putunbr(n / 10, len);
		ft_putchar((n % 10) + '0', len);
	}
}

void	specifier2(va_list value, char c, int *len)
{
	if (c == 'd')
		ft_putnbr(va_arg(value, int), len);
	if (c == 's')
		ft_putstr(va_arg(value, char *), len);
	if (c == 'c')
		ft_putchar(va_arg(value, int), len);
	if (c == 'i')
		ft_putnbr(va_arg(value, int), len);
}

void	specifier(va_list value, char c, int *len)
{
	unsigned int	a;

	if (c == 'u')
	{	
		a = va_arg(value, unsigned int);
		if (a != 0)
			ft_putunbr(a, len);
		if (a == 0)
			*len += write(1, "0", 1);
	}
	if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_hex(va_arg(value, long int), "0123456789abcdef", len);
	}
	if (c == 'x')
		ft_hex(va_arg(value, unsigned int), "0123456789abcdef", len);
	if (c == 'X')
		ft_hex(va_arg(value, unsigned int), "0123456789ABCDEF", len);
	if (c == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	value;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(value, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			specifier(value, str[i], &len);
			specifier2(value, str[i], &len);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(value);
	return (len);
}

// #include <stdio.h>
//   int main()
//  {
// 	ft_printf("%d", 23456);
// 	printf("\n%d\n",23456 );

// 	ft_printf("\n%s", "esra");
// 	printf("\n%s\n","esra" );

// 	ft_printf("\n%c", 'e');
// 	printf("\n%c\n",'e' );

// 	ft_printf("\n%p", 23456);
// 	printf("\n%p\n",23456 );

// 	ft_printf("\n%x", 23456);
// 	printf("\n%x\n",23456 );

// 	ft_printf("\n%i", 23456);
// 	printf("\n%i\n",23456 );

// 	ft_printf("\n%X" ,23456 );
// 	printf("\n%X\n", 23456 );

//  	ft_printf("\n%u", 0);
//  	printf("\n%u\n", 0);

// 	ft_printf("\n%%" , '%' );
// 	printf("\n%%" , '%' );
//  }
