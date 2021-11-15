/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:37:54 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:16:36 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	void	*start;

	start = dst;
	while (len)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		src++;
		len--;
	}
	return (start);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	if (!src || !dst)
		return (dst);
	while (len)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		dst++;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst);
		src++;
		len--;
	}
	return (NULL);
}
