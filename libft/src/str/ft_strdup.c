/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:11:41 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:20:56 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	size;

	size = ft_strlen(src);
	new = ft_calloc((size + 1), sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, src, size + 1);
	return (new);
}
