/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmodif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:45:12 by pthomas           #+#    #+#             */
/*   Updated: 2021/03/04 09:23:09 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (src == 0)
	{
		dst = 0;
		return (0);
	}
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (ldst >= dstsize)
		return (dstsize + lsrc);
	while (src[i] && (i + ldst < dstsize - 1))
	{
		dst[i + ldst] = src[i];
		i++;
	}
	dst[i + ldst] = '\0';
	return (ldst + lsrc);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	i = -1;
	if (s == 0)
		return (0);
	dst = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (0);
	while (s[++i])
		dst[i] = (*f)(i, s[i]);
	dst[i] = 0;
	return (dst);
}

char	*ft_strrev(char *s)
{
	int		i;
	char	c;
	int		len;

	i = 0;
	len = ft_strlen(s);
	while (i < len / 2)
	{
		c = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = c;
		i++;
	}
	return (s);
}
