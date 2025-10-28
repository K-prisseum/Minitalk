/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:03:07 by itoudji           #+#    #+#             */
/*   Updated: 2023/11/28 01:29:30 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

int		ft_putchar_int(int c);
int		ft_putstr_int(char *s);
int		count_u_digits(unsigned int nb);
int		count_digits(int nb);

int		ft_print_char(char const c);
int		ft_print_str(char *str);
int		ft_print_nbr(int nb);
int		ft_print_u_nbr(unsigned int nb);
int		ft_print_percent(void);

int		ft_print_hex(unsigned int nb, int min);
int		ft_put_longhexa(unsigned long long nb);
int		ft_print_ptr(unsigned long long ptr);

int		ft_printf(char const *format, ...);

#endif
