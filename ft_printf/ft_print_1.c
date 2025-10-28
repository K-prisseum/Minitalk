/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:30:35 by itoudji           #+#    #+#             */
/*   Updated: 2023/11/30 21:15:07 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char const c)
{
	ft_putchar_fd((char)c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd((char *) str, 1);
	return (ft_strlen(str));
}

int	ft_print_nbr(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (count_digits(nb));
}

int	ft_print_u_nbr(unsigned int nb)
{
	if (nb < 10)
		ft_putchar_fd('0' + nb, 1);
	if (nb >= 10)
	{
		ft_print_u_nbr(nb / 10);
		ft_print_u_nbr(nb % 10);
	}
	return (count_u_digits(nb));
}

int	ft_print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
