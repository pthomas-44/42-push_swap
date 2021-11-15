/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 04:16:43 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:57:42 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_countwords(const char *s, char sep)
{
	size_t	i;
	size_t	nb_of_words;

	i = 0;
	nb_of_words = 0;
	while (s[i])
	{
		if (s[i] && s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			nb_of_words++;
		i++;
	}
	return (nb_of_words);
}

static char	*get_next_word(const char **str, char sep)
{
	const char	*start;

	while (*(*str) && *(*str) == sep)
		(*str)++;
	start = (*str);
	while (*(*str) && *(*str) != sep)
		(*str)++;
	return (ft_substr(start, 0, (*str) - start));
}

char	**ft_split(char const *str, char sep)
{
	size_t		i;
	size_t		nb_of_words;
	char		**words;

	nb_of_words = ft_countwords(str, sep);
	if (!nb_of_words)
		return (NULL);
	words = ft_calloc(nb_of_words + 1, sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < nb_of_words)
	{
		words[i] = get_next_word(&str, sep);
		if (!words[i])
			free_array(&words, nb_of_words);
		i++;
	}
	words[i] = NULL;
	return (words);
}
