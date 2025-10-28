/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:35:23 by itoudji           #+#    #+#             */
/*   Updated: 2023/11/28 01:47:41 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char c, va_list *params, int *count)
{
	if (c == 'c')
		*count += ft_print_char((char)va_arg(*params, int));
	if (c == 's')
		*count += ft_print_str(va_arg(*params, char *));
	if (c == 'p')
		*count += ft_print_ptr(va_arg(*params, unsigned long long));
	if (c == 'd' || c == 'i')
		*count += ft_print_nbr(va_arg(*params, int));
	if (c == 'u')
		*count += ft_print_u_nbr(va_arg(*params, unsigned int));
	if (c == 'x')
		*count += ft_print_hex(va_arg(*params, unsigned int), 1);
	if (c == 'X')
		*count += ft_print_hex(va_arg(*params, unsigned int), 0);
	if (c == '%')
		*count += ft_print_percent();
}

int	ft_printf(char const *format, ...)
{
	va_list	params;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_format(format[i + 1], &params, &count);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			i++;
			count++;
		}
	}
	va_end(params);
	return (count);
}
