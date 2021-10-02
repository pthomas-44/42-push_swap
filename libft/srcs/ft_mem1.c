/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 13:20:51 by pthomas           #+#    #+#             */
/*   Updated: 2021/08/19 11:40:30 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = b;
	while (len--)
		*p++ = c;
	return (b);
}

void	ft_bzero(void *b, size_t n)
{
	ft_memset(b, 0, n);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*p;

	p = dst;
	if (src == 0 && dst == 0)
		return (0);
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (p);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		if (*(unsigned char *)(src - 1) == (unsigned char)c)
			return (dst);
	}
	return (0);
}
