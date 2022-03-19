/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:24:29 by ebudak            #+#    #+#             */
/*   Updated: 2022/02/24 03:24:30 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_hex(unsigned long int a, char *s, int *len)
{
	int		b;

	if (a < 16)
	{
		*len += write(1, &s[a], 1);
		return ;
	}
	b = (a % 16);
	a = a / 16;
	if (a < 16)
	{
			*len += write(1, &s[a], 1);
			*len += write(1, &s[b], 1);
	}
	if (a >= 16)
	{
		ft_hex(a, s, len);
			*len += write(1, &s[b], 1);
	}
}

void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char *s, int *len)
{
	if (!s)
	{
		ft_putstr("(null)", len);
	}
	else
		*len += write(1, s, ft_strlen(s));
}
