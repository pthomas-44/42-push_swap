/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:30:29 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/09 13:05:06 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int value, size_t len)
{
	void	*start;

	start = dst;
	while (len)
	{
		*(unsigned char *)dst = value;
		dst++;
		len--;
	}
	return (start);
}
