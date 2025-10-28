/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:04:20 by itoudji           #+#    #+#             */
/*   Updated: 2023/11/28 01:26:24 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(int c)
{
	int	succes;

	succes = write(1, &c, 1);
	if (succes <= 0)
		return (0);
	return (1);
}

int	ft_putstr_int(char *s)
{
	int	res;

	res = 0;
	while (*s)
	{
		ft_putchar_int(*s);
		s++;
		res++;
	}
	return (res);
}

int	count_u_digits(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		++len;
	while (nb > 0)
	{
		nb /= 10;
		++len;
	}
	return (len);
}

int	count_digits(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
		len += 10;
	if (nb <= 0)
	{
		nb *= -1;
		++len;
	}
	while (nb > 0)
	{
		nb /= 10;
		++len;
	}
	return (len);
}
