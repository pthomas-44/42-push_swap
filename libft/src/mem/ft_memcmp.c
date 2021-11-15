/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dev <dev@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:05:54 by pthomas           #+#    #+#             */
/*   Updated: 2021/11/13 23:16:28 by dev              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	int	diff;

	if (!src1)
		return (*(unsigned char *)src2);
	else if (!src2)
		return (*(unsigned char *)src1);
	while (n)
	{
		diff = *(unsigned char *)src1 - *(unsigned char *)src2;
		if (diff)
			return (diff);
		src1++;
		src2++;
		n--;
	}
	return (0);
}
