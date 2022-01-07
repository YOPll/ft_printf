/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:04:03 by zyacoubi          #+#    #+#             */
/*   Updated: 2021/12/05 23:42:48 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	udi_tr(const char *str, va_list list, int *r)
{
	int				i;
	unsigned int	j;

	if (*str == 'd' || *str == 'i')
	{
		i = va_arg(list, int);
		ft_putnbr(i, r);
	}
	else if (*str == 'u')
	{
		j = va_arg(list, unsigned int);
		unsigned_tr(j, r);
	}
}

void	string_tr(const char *str, va_list list, int *r)
{
	char	*s;
	char	c;
	int		i;

	i = 0;
	if (*str == 's')
	{
		s = va_arg(list, char *);
		if (!s)
		{
			*r += write(1, "(null)", 6);
			return ;
		}
		while (s[i])
			*r += write(1, &s[i++], 1);
	}
	else if (*str == 'c')
	{
		c = va_arg(list, int);
		*r += write(1, &c, 1);
	}
}

void	hex_tr(const char *str, va_list list, int *r)
{
	int				i;
	unsigned int	x;
	unsigned long	j;

	i = 0;
	if (*str == 'x' || *str == 'X')
	{
		x = va_arg(list, unsigned int);
		if (*str == 'x')
			i = 1;
		ft_hex(x, i, r);
	}
	else if (*str == 'p')
	{
		j = va_arg(list, unsigned long);
		*r += write(1, "0x", 2);
		ft_hexp(j, r);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		j;

	va_start(list, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] != '%')
			{
				ft_check(str, list, &j, i);
			}
			else if (str[i])
				j += write(1, &str[i], 1);
		}
		else
			j += write(1, &str[i], 1);
		if (str[i])
			i++;
	}
	return (va_end(list), j);
}
