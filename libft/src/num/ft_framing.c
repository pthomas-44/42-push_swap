/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_framing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:06:44 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/10 11:17:28 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_framing(int min, int nb, int max)
{
	return (min <= nb && nb <= max);
}

float	ft_framingf(float min, float nb, float max)
{
	return (min <= nb && nb <= max);
}
