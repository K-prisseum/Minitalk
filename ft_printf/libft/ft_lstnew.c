/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itoudji <itoudji.42lehavre.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:38:20 by itoudji           #+#    #+#             */
/*   Updated: 2023/11/11 19:04:47 by itoudji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*zeb;

	zeb = malloc(sizeof(t_list));
	if (!zeb)
		return (NULL);
	zeb->content = content;
	zeb->next = NULL;
	return (zeb);
}
