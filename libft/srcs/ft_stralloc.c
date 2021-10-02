/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 06:55:11 by pthomas           #+#    #+#             */
/*   Updated: 2021/03/04 09:34:02 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	i = -1;
	cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!cpy)
		return (0);
	while (s1[++i])
		cpy[i] = s1[i];
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (len > ft_strlen(s))
		len = ft_strlen(&s[start]);
	str = ft_calloc(sizeof(char), (len + 1));
	if (!s || !str)
		return (0);
	if (start <= ft_strlen(s))
		ft_strlcpy(str, &s[start], len + 1);
	return (str);
}

static int	ft_isset(char const *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*end;
	char		*str;

	if (s1 == 0)
		return (0);
	end = s1 + ft_strlen(s1) - 1;
	while (ft_isset(set, *s1))
		s1++;
	if (*s1 == 0)
		return (str = ft_calloc(1, sizeof(char)));
	while (ft_isset(set, *end))
		end--;
	str = malloc(sizeof(char) * (end - s1 + 2));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, end - s1 + 2);
	return (str);
}
