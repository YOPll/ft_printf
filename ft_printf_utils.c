/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:44:08 by zyacoubi          #+#    #+#             */
/*   Updated: 2021/12/05 23:44:13 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned int x, int i, int *r)
{
	if (x >= 16)
	{
		ft_hex(x / 16, i, r);
		ft_hex(x % 16, i, r);
	}
	else
	{
		if (i == 0)
			*r += write(1, &"0123456789ABCDEF"[x], 1);
		else if (i == 1)
			*r += write(1, &"0123456789abcdef"[x], 1);
	}
}

void	ft_putnbr(int nb, int *r)
{
	char	*num;

	num = "0123456789";
	if (nb == -2147483648)
	{
		*r += write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		*r += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, r);
	*r += write(1, &num[nb % 10], 1);
}

void	ft_hexp(unsigned long x, int *r)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (x >= 16)
		ft_hexp(x / 16, r);
	*r += write(1, &hex[x % 16], 1);
}

void	unsigned_tr(unsigned int n, int *r)
{
	if (n >= 10)
	{
		unsigned_tr(n / 10, r);
		unsigned_tr(n % 10, r);
	}
	else
		*r += write(1, &"0123456789"[n], 1);
}
