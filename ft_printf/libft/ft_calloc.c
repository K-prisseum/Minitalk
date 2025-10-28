/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:47:28 by itoudji           #+#    #+#             */
/*   Updated: 2023/10/29 18:12:14 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char		*res;
	size_t				i;

	i = 0;
	res = malloc(nmemb * size);
	if (!res)
	{
		return (NULL);
	}
	while (size * nmemb > i)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
