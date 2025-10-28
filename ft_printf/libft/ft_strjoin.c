/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 21:18:48 by itoudji           #+#    #+#             */
/*   Updated: 2023/10/29 21:54:59 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*zeb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	zeb = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!zeb)
		return (NULL);
	while (s1[i])
	{
		zeb[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		zeb[j] = s2[i];
		i++;
		j++;
	}
	zeb[j] = '\0';
	return (zeb);
}
