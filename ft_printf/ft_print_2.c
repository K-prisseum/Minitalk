/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:33:14 by itoudji           #+#    #+#             */
/*   Updated: 2023/11/28 01:41:44 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int min)
{
	char	tmp;
	char	*base;
	int		count;

	count = 0;
	base = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_print_hex(n / 16, min);
		count += ft_print_hex(n % 16, min);
	}
	else
	{
		if (min)
		{
			tmp = ft_tolower(base[n]);
			write(1, &tmp, 1);
		}
		else
		{
			write(1, &base[n], 1);
		}
		count++;
	}
	return (count);
}

int	ft_put_longhexa(unsigned long long nb)
{
	char	*hexabase;
	char	digit;
	int		count;

	count = 0;
	hexabase = "0123456789abcdef";
	if (nb >= 16)
		count += ft_put_longhexa((nb / 16));
	digit = hexabase[nb % 16];
	count += ft_putchar_int(digit);
	return (count);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	if (ptr == 0)
		return (ft_putstr_int("(nil)"));
	count = ft_putstr_int("0x");
	count += ft_put_longhexa(ptr);
	return (count);
}
