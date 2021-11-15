/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:55:11 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/11 17:18:28 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *src, char const *charset)
{
	const char	*start;
	const char	*end;

	if (!src || !charset)
		return ((char *)src);
	start = src;
	end = src + ft_strlen(src) - 1;
	while (*start && ft_strchr(charset, *start))
		start++;
	while (end > src && ft_strchr(charset, *end))
		end--;
	if (start >= end)
		return (NULL);
	return (ft_substr(start, 0, end - start + 1));
}
