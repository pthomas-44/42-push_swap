/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:46:45 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:30:10 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_max_len;

	if (!src || start > ft_strlen(src))
		return (NULL);
	new_max_len = ft_strlen(&src[start]);
	if (len > new_max_len)
		len = new_max_len;
	new = ft_calloc((len + 1), sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &src[start], len + 1);
	return (new);
}
