/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:01:31 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:15:47 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int value, size_t lenn)
{
	while (lenn)
	{
		if (*(unsigned char *)src == (unsigned char)value)
			return ((unsigned char *)src);
		src++;
		lenn--;
	}
	return (NULL);
}
