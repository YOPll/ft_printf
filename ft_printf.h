/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyacoubi <mrx.ga10@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:18:37 by zyacoubi          #+#    #+#             */
/*   Updated: 2021/12/05 23:43:23 by zyacoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	udi_tr(const char *str, va_list list, int *r);
void	string_tr(const char *str, va_list list, int *r);
void	hex_tr(const char *str, va_list list, int *r);
void	ft_putnbr(int nb, int *r);
int		ft_printf(const char *str, ...);
void	ft_hex(unsigned int x, int i, int *r);
void	ft_hexp(unsigned long x, int *r);
void	unsigned_tr(unsigned int n, int *r);
void	ft_check(const char *str, va_list list, int *j, int i);

#endif
