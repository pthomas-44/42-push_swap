/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:39:29 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/14 00:06:24 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*error_handling(const char *s1, const char *s2, int alloc_args)
{
	char	*new;

	if (!s1)
		new = ft_strdup(s2);
	else if (!s2)
		new = ft_strdup(s1);
	if (alloc_args == 1 || alloc_args == 3)
		free((char *)s1);
	if (alloc_args > 2)
		free((char *)s2);
	return (new);
}

char	*ft_strjoin(const char *s1, const char *s2, int alloc_args)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return (error_handling(s1, s2, alloc_args));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!new)
		return (error_handling(NULL, NULL, alloc_args));
	ft_strlcpy(new, s1, s1_len + 1);
	ft_strlcat(new, s2, s1_len + s2_len + 1);
	if (alloc_args == 1 || alloc_args == 3)
		free((char *)s1);
	if (alloc_args > 2)
		free((char *)s2);
	return (new);
}
