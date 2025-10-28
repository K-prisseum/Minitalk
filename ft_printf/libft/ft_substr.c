/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:17:44 by itoudji           #+#    #+#             */
/*   Updated: 2023/10/29 20:52:47 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*mini;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	mini = malloc(sizeof(char) * (len + 1));
	if (!mini)
		return (NULL);
	while (start + i < ft_strlen(s) && i < len)
	{
		mini[i] = s[start + i];
		i++;
	}
	mini[i] = '\0';
	return (mini);
}
