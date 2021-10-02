/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:18:51 by pthomas           #+#    #+#             */
/*   Updated: 2021/06/07 19:25:39 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_to_lower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 32;
	return (c);
}

int	ft_to_upper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}

int	ft_framing(int min, int nb, int max)
{
	if (min <= nb && nb <= max)
		return (1);
	else
		return (0);
}

float	ft_framingf(float min, float nb, float max)
{
	if (min <= nb && nb <= max)
		return (1);
	else
		return (0);
}
