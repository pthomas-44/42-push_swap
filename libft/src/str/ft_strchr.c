/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:21:06 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/15 22:18:26 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strrchr(const char *str, int c)
{
	const char	*start;

	start = str;
	str += ft_strlen(str);
	while (str >= start)
	{
		if (*str == c)
			return ((char *)str);
		str--;
	}
	return (NULL);
}

char	*ft_strchrstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&(s1[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!needle || !needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (!ft_strncmp(needle, &haystack[i], ft_strlen(needle)))
			return ((char *)&(haystack[i]));
		i++;
	}
	return (NULL);
}

size_t	ft_strchrstr_count(char *str, char *charset)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (ft_strchr(charset, *str))
			count++;
		str++;
	}
	return (count);
}
