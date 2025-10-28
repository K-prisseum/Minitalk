/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:04:10 by itoudji           #+#    #+#             */
/*   Updated: 2023/11/11 14:27:56 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	count_size(long nb)
{
	size_t	zeb;

	zeb = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		zeb++;
	}
	if (nb == 0)
		zeb = 1;
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			zeb++;
		}
	}
	return (zeb);
}

char	*ft_itoa(int n)
{
	size_t	zeb;
	long	nb;
	char	*str;
	int		nigga;

	zeb = count_size((long) n);
	str = (char *) malloc(sizeof(char) * (zeb + 1));
	if (str == NULL)
		return (NULL);
	nb = (long) n;
	nigga = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
		nigga = 1;
	}
	str[zeb] = '\0';
	while (zeb > (size_t) nigga)
	{
		str[zeb - 1] = nb % 10 + '0';
		nb = nb / 10;
		zeb--;
	}
	return (str);
}
