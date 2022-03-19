/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebudak <ebudak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 03:24:32 by ebudak            #+#    #+#             */
/*   Updated: 2022/02/25 19:53:49 by ebudak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(const char *s);
void	ft_pointer(unsigned long i, char *s, int *len);
void	ft_hex(unsigned long int a, char *s, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putunbr(unsigned int n, int *len);
void	specifier2(va_list value, char c, int *len);
void	specifier(va_list value, char c, int *len);

#endif