/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:39:45 by pthomas           #+#    #+#             */
/*   Updated: 2021/03/08 15:39:34 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_str_isalpha(char *s)
{
	while (*s)
		if (!ft_isalpha(*s++))
			return (0);
	return (1);
}

int	ft_str_isdigit(char *s)
{
	while (*s)
		if (!ft_isdigit(*s++))
			return (0);
	return (1);
}

int	ft_str_isalnum(char *s)
{
	while (*s)
		if (!ft_isalnum(*s++))
			return (0);
	return (1);
}

int	ft_str_isascii(char *s)
{
	while (*s)
		if (!ft_isascii(*s++))
			return (0);
	return (1);
}

int	ft_str_isprint(char *s)
{
	while (*s)
		if (!ft_isprint(*s++))
			return (0);
	return (1);
}
